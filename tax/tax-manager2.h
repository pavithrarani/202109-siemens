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

class TaxManager
{          
    
    public:      

        void fileTax(string pan, int year){
            //Step 1 get the financial details;
            FinancialInfo info= fetchData(pan,year);

            //Step 2 calculate tax
            int tax = calculateTax(info);      

            //Step 3 submit the tex
            submitTax(pan,year,tax);

        }

        int calculateTax(FinancialInfo info){
            if(info.year==2020) 
                return (info.income-info.expense-info.investment)*(0.2 -  0.05*(info.gender==Gender::Female));
            else
                return (info.income-(info.expense>50000?50000:info.expense)-(info.investment>100000?100000:info.investment))* 0.15;
        }


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

        void submitTax(string pan, int year, int tax){
            cout<<"Tax for PAN:"<<pan+" FY:"<<year<<" is "<<tax<<endl;
        }
};