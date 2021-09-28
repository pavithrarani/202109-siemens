
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

class TaxCalculator2021:public  TaxCalculator {
    public:
    int calculateTax(FinancialInfo info){       
        //rules for Males remains unchanged
        //Ladies gets 5% extra rebate on previous years calculation
        //How do I reuse TaxCaclculator 2020
    }
};
