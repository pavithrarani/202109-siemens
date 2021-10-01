#pragma once
#include <iostream>
using namespace std;

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
