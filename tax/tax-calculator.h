#pragma once
#include <iostream>
using namespace std;

class TaxCalculator{

    public:
    virtual int calculateTax(FinancialInfo info)=0;
};


class TaxCalculator2019: public TaxCalculator{
    static TaxCalculator2019 * instance;
    TaxCalculator2019(){}

    public:
    static TaxCalculator2019 * getInstance(){
        if(instance==NULL)
            instance=new TaxCalculator2019;
        return instance;
    }

    int calculateTax(FinancialInfo info){
        
        return (info.income-info.expense-info.investment)*(0.2 -  0.05*(info.gender==Gender::Female));
       
    }
};

class TaxCalculator2020: public TaxCalculator {
    private:
     TaxCalculator2020(){
         cout<<"tax calcualator 2020 created\n";
     }
    public:
    int calculateTax(FinancialInfo info){       
        return (info.income-(info.expense>50000?50000:info.expense)-(info.investment>100000?100000:info.investment))* 0.15;
    }

    static TaxCalculator2020 * getInstance(){
        static TaxCalculator2020 * instance=new TaxCalculator2020();

        return instance;
    }
};

// class TaxCalculator2021_V1:public  TaxCalculator2020 {

//     public:
//     int calculateTax(FinancialInfo info){       
//         int tax= TaxCalculator2020::calculateTax(info);
//         if(info.gender==Gender::Female)
//             tax=tax*0.95;

//         return tax;
//     }
// };


class TaxCalculator2021:public  TaxCalculator {

    TaxCalculator2020 old;
    public:
    int calculateTax(FinancialInfo info){       
        int tax= old.calculateTax(info);
        if(info.gender==Gender::Female)
            tax=tax*0.95;
        return tax;
    }
};


