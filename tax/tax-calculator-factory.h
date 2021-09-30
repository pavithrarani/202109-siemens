#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
#include "tax-calculator.h"

class CalculatorNotFound :public exception{

    int year;

    public:
    CalculatorNotFound(int year){
        this->year=year;
    }

    const char * what() const throw(){
        
      return "Tax Calculator Not Found";
    }

    int getYear() const { return year; }

};

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