#pragma once
#include <iostream>
#include <string>
#include "finance-info.h"
#include "tax-submitter.h"
#include "tax-calculator.h"
using namespace std;


class TaxManager
{          
    FinancialInfoSource *source;
    TaxCalculator *calculator;
    TaxSubmitter *submitter;
    public:      

        //default dependencies
        TaxManager(TaxCalculator *calculator)
        {
            this->source = new FixedFinancialInfoSource();
            this->calculator = calculator;
            this->submitter = new ConsoleTaxSubmitter();
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