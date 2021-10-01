#pragma once
#include <iostream>
#include <map>
using namespace std;



union Data{    
        int iValue;
        double dValue;
        string str;
        void *object;
        Data(){ object=NULL; }   
        ~Data(){}        
};

Data * intData(int value){ 
    Data * data=new Data(); 
    data->iValue=value; 
    return data;
}

Data * doubleData(double value){ 
    Data * data=new Data(); 
    data->dValue=value; 
    return data;
}


Data * stringData(string value){ 
    Data * data=new Data(); 
    data->str=value; 
    return data;
}



class FinanceInfoProvider
{
    public:
        virtual map<string,Data*> fetchInfo(string pan, int year)=0;
};



class FixedFinanceInfoProvider: public FinanceInfoProvider{
    map<string,Data*> info;
    public:

    FixedFinanceInfoProvider(){
       info["income"] = intData(500000);
       info["expense"] = intData(200000);
       info["investment"]=intData(200000);
      // info["location"]=stringData("KA");
      // info["age"]=intData(10);
    }

    void addInfo(string key, Data * data){
        info[key]=data;
    }


    virtual map<string,Data*> fetchInfo(string pan, int year){
        
      //  info["pan"]=stringData(pan);
        info["year"]=intData(year);
        info["gender"]= intData(pan[0]);
        return info;
    }

};

