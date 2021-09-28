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

    char *filename;
    FILE * file;
    public:
    FileTaxSubmitter(char *fileName){
        this->filename=filename;
        this->file=fopen(filename,"a");
    }

    ~FileTaxSubmitter(){
        fclose(this->file);
    }


    void submitTax(string pan, int year, int tax){
        fprintf(file,"%s,%d,%d\n",pan,year,tax);
        fflush(file);
    }

};