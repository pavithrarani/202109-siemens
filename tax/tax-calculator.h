#pragma once

class TaxCalculator{

    public:
    virtual int calculateTax(FinancialInfo info)=0;
};


class TaxCalculator2019: public TaxCalculator{
    public:
    int calculateTax(FinancialInfo info){
        
        return (info.income-info.expense-info.investment)*(0.2 -  0.05*(info.gender==Gender::Female));
       
    }
};

class TaxCalculator2020: public TaxCalculator {
    public:
    int calculateTax(FinancialInfo info){       
        return (info.income-(info.expense>50000?50000:info.expense)-(info.investment>100000?100000:info.investment))* 0.15;
    }
};

class TaxCalculator2021_V1:public  TaxCalculator2020 {

    public:
    int calculateTax(FinancialInfo info){       
        int tax= TaxCalculator2020::calculateTax(info);
        if(info.gender==Gender::Female)
            tax=tax*0.95;

        return tax;
    }
};


class TaxCalculator2021:public  TaxCalculator {

    TaxCalculator2020 old;
    public:
    int calculateTax(FinancialInfo info){       
        int tax= old.calculateTax(info);
        if(info.gender==Gender::Female)
            tax=tax*0.95;
        return tax;
    }
};


