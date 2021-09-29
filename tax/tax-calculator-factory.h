#pragma once
#include <iostream>
#include <exception>
using namespace std;
#include "tax-calculator.h"



class TaxCalculatorFactory{

    public:
        virtual TaxCalculator* forYear(int year)=0;
};

class SimpleTaxCalculatorFactory:public TaxCalculatorFactory{

    public:

    TaxCalculator * forYear(int year){

        switch(year){

            case 2019: return new TaxCalculator2019();

            case 2020: return new TaxCalculator2020();

            default: throw new exception("invalid year");

        };

    }       

};