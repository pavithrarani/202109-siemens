#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "calculator-exception.h"
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

            case 2019: 
                //return new TaxCalculator2019();
                return TaxCalculator2019::getInstance();

            case 2020: 
                //return new TaxCalculator2020();
                return TaxCalculator2020::getInstance();

            default: {
                
                throw  CalculatorNotFound(year);
            }
        };

    }       

};


class SmartTaxCalculatorFactory:public TaxCalculatorFactory{

    public:

    TaxCalculator * forYear(int year){

        // switch(year){

        //     case 2019: 
        //         return new TaxCalculator2019();

        //     case 2020: 
        //         return new TaxCalculator2020();

        //     default: {
                
        //         throw  CalculatorNotFound(year);
        //     }
        // };


        throw  CalculatorNotFound(year);
    }       

};