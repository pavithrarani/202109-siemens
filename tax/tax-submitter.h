#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class TaxSubmitter{
    public:
    virtual void submitTax(string pan, int year, int tax)=0;
};


class ConsoleTaxSubmitter:public TaxSubmitter{
    public:
    void submitTax(string pan, int year, int tax){
        cout<<"Tax for PAN:"<<pan+" FY:"<<year<<" is "<<tax<<endl;
    }
};


class CustomTaxSubmitter: public ConsoleTaxSubmitter {
  public:
  void submitTax(string pan, int year, int tax){
      cout<<"CUSTOM\t";
      ConsoleTaxSubmitter::submitTax(pan, year, tax);
  }
};

class FileTaxSubmitter: public TaxSubmitter {

    
    FILE * file;
    public:
    FileTaxSubmitter(const char *fileName){
        
        this->file=fopen(fileName,"a");
    }

    ~FileTaxSubmitter(){
        fclose(this->file);
    }


    void submitTax(string pan, int year, int tax){
        fprintf(file, "%s,%d,%d\n",pan.c_str(),year,tax);
        fflush(file);
    }

};