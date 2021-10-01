#pragma once
#include <iostream>
#include <map>
#include "finance-info.h"
#include "finance-info-provider.h"
#include "tax-calculator.h"
#include "calculator-exception.h"
using namespace std;

class TaxCalculatorV2
{
    public:
    virtual int calculateTax(map<string,Data*> info)=0;
};

class TaxCalculator2022 : public TaxCalculatorV2
{
    public:
    int calculateTax(map<string,Data*> info){
        int income= info["income"]->iValue;
        int investment=info["investment"]->iValue;
        int gender= info["gender"]->iValue;
        int age= info["age"]->iValue;

        int tax= (income-investment) * 15/100;
        
        if(gender=='f')
            tax=tax*9/10;
        
        if(age<18 || age>65)
            tax=tax*9/10;

        return tax;

    }
};


class CalculatorV1ToV2Adapter:public TaxCalculatorV2
{
    TaxCalculator * old;
    public:
    CalculatorV1ToV2Adapter(TaxCalculator * old){
        this->old=old;
    }
    
    int calculateTax(map<string,Data*> info){
        FinancialInfo data;
        data.income= info["income"]->iValue;
        data.expense=info["expense"]->iValue;
        data.investment=info["investment"]->iValue;
        data.gender=info["gender"]->iValue=='m'?Gender::Male:Gender::Female;

        return old->calculateTax(data);
    }
    
};

class TaxCalculatorV2Provider
{
    public:
    virtual TaxCalculatorV2 * forYear(int year)=0;
};




class SmartCalculator2Provider :public  TaxCalculatorV2Provider
{
    map<int, TaxCalculatorV2 *> calculators;

    SmartCalculator2Provider(){
        //add exisitng calculators here
        addCalculator(2022, new TaxCalculator2022());
        addCalculator(2019, new CalculatorV1ToV2Adapter(TaxCalculator2019::getInstance()));
    }
   
public:

    


    static SmartCalculator2Provider *instance(){
        static SmartCalculator2Provider * _instance=new SmartCalculator2Provider();
        return _instance;
    }
    

    void addCalculator(int year, TaxCalculatorV2 * calculator){
        calculators[year]=calculator;
    }


    TaxCalculatorV2 * forYear(int year)
    {
        if( calculators.find(year) != calculators.end() ) //calculator is not present
            return calculators[year];
        else
            throw  CalculatorNotFound(year);
    }
};