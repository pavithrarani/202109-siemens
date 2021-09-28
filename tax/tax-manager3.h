#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Gender{Male,Female};

struct FinancialInfo{
    Gender gender;
    string pan;
    int year;
    int income;
    int expense;
    int investment;
};

class FinancialInfoSource{
    public:
     FinancialInfo fetchData(string pan, int year){
            FinancialInfo info;
            info.gender= pan[0]=='m'?Gender::Male:Gender::Female;
            info.income=500000;
            info.expense=20000;
            info.investment=150000;
            info.pan=pan;
            info.year=year;
            return info;
        }
};

class TaxCalculator{
    public:
    int calculateTax(FinancialInfo info){
        if(info.year==2020) 
            return (info.income-info.expense-info.investment)*(0.2 -  0.05*(info.gender==Gender::Female));
        else
            return (info.income-(info.expense>50000?50000:info.expense)-(info.investment>100000?100000:info.investment))* 0.15;
    }


};

class TaxSubmitter{
    public:
    virtual void submitTax(string pan, int year, int tax){
        cout<<"Tax for PAN:"<<pan+" FY:"<<year<<" is "<<tax<<endl;
    }
};

class CustomTaxSubmitter: public TaxSubmitter {
  public:
  void submitTax(string pan, int year, int tax){
      cout<<"CUSTOM\t";
      TaxSubmitter::submitTax(pan, year, tax);
  }
};

class TaxManager
{          
    FinancialInfoSource *source;
    TaxCalculator *calculator;
    TaxSubmitter *submitter;
    public:      

        //default dependencies
        TaxManager()
        {
            this->source = new FinancialInfoSource();
            this->calculator = new TaxCalculator();
            this->submitter = new TaxSubmitter();
        }

        void setFinancialInfoSource(FinancialInfoSource* source){ this->source=source;}
        void setTaxCalculator(TaxCalculator* calculator){ this->calculator=calculator;}
        void setTaxSubmitter(TaxSubmitter *submitter){ this->submitter=submitter;}


        void fileTax(string pan, int year){
            //Step 1 get the financial details;
            FinancialInfo info= source->fetchData(pan,year);

            //Step 2 calculate tax
            int tax = calculator->calculateTax(info);      

            //Step 3 submit the tex
            submitter->submitTax(pan,year,tax);

        }
        
};