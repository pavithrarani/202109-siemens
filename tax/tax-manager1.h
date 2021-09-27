#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Gender{Male,Female};

class TaxManager
{          
    
    public:      

        void fileTax(string pan, int year){
            //Step 1 get the financial details;
            Gender gender= pan[0]=='m'?Gender::Male:Gender::Female;
            int income=500000;
            int expense=20000;
            int investment=150000;

            //Step 2 calculate tax
            double tax=0;
            
            if(year==2020) 
                tax=(income-expense-investment)*(0.2 -  0.05*(gender==Gender::Female));
            else
                tax=(income-(expense>50000?50000:expense)-(investment>100000?100000:investment))* 0.15;      

            //Step 3 submit the tex
            cout<<"Tax for PAN:"<<pan+" FY:"<<year<<" is "<<tax<<endl;

        }
};