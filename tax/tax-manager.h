#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Gender{Male,Female};

class TaxManager
{
    //fields
        
    
    public:
        TaxManager(){
            //initialize fields
        }
        //Methods

        void fileTax(string pan, int year){
            //Step 1 get the financial details;
            Gender gender= pan[0]=='m'?Gender::Male:Gender::Female;
            int income=500000;
            int expense=20000;
            int investment=100000;

            //Step 2 calculate tax
            double tax=tax= (income-expense-investment)*(0.2 - - 0.05*(gender==Gender::Female));
            
            //Step 3 submit the tex

            cout<<"Tax for PAN:"<<pan+" FY:"<<year<<" is "<<tax<<endl;

        }
};