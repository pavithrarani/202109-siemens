#pragma once
#include <iostream>
#include "tax-submitter.h"
#include "finance-info-provider.h"
#include "tax-calculator-v2.h"
#include <map>
using namespace std;




class TaxManagerV2
{
    //fields
    TaxSubmitter * submitter;
    FinanceInfoProvider * provider;
    TaxCalculatorV2Provider * calculatorProvider;
    
    public:
        
        void setFinanceInfoProvider(FinanceInfoProvider* source){ this->provider=source;}
        void setTaxCalculatorFactory(TaxCalculatorV2Provider* calculatorProvider){ this->calculatorProvider=calculatorProvider;}
        void setTaxSubmitter(TaxSubmitter *submitter){ this->submitter=submitter;}


        TaxManagerV2(){
            //initialize fields
            //this->calculatorFactory=new SimpleTaxCalculatorFactory();
            //this->source = new FixedFinancialInfoSource();            
            this->submitter = new ConsoleTaxSubmitter();
            this->provider= new FixedFinanceInfoProvider();           
            this->calculatorProvider= SmartCalculator2Provider::instance();
        }
        
         void fileTax(string pan, int year){
            //Step 1 get the financial details;
           map<string,Data *> info= provider->fetchInfo(pan,year);

            //Step 2 calculate tax
            TaxCalculatorV2 * calculator= calculatorProvider->forYear(year);
            int tax = calculator->calculateTax(info);      

            //Step 3 submit the tex
            submitter->submitTax(pan,year,tax);

        }
};