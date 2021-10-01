#pragma once
#include <iostream>
using namespace std;

class ITankActionMode
{
    public:
    virtual void moveAction()=0;
    virtual void attackAction()=0;
    virtual void defendAction()=0;
};



class ChampionTank
{
    //fields
    ITankActionMode * mode;      
    
    public:
        ChampionTank(){
            //initialize fields
            
        }
        //Methods
        void setMode(ITankActionMode* mode){
            this->mode=mode;
        }
        void move(void)
        {
            mode->moveAction();
        }

        void attack()
        {
            mode->attackAction();
        }

        void defend()
        {
            mode->defendAction();
        }

};

class AggresiveActionMode:public  ITankActionMode
{
    public:
        void moveAction()
        {
            cout<<"Move Towards Enemy"<<endl;                
        }

        void attackAction(void)
        {
            cout<<"Fire at Enemy"<<endl;
        }

        void defendAction(void)
        {
            cout<<"Cover Fire"<<endl;
        }
};

class DefensiveActionMode: public ITankActionMode
{
    public:
        void moveAction()
        {
            cout<<"Move Away from Enemy"<<endl;
        }

        void attackAction(void)
        {
            cout<<"Hold Fire"<<endl;
        }

        void defendAction(void)
        {
            cout<<"Hide"<<endl;
        }
};

class GurillaActionMode: public ITankActionMode
{
    int strategyId;
    public:
        GurillaActionMode(int strategyId=0){
            this->strategyId=strategyId;
        }
        void moveAction()
        {
            cout<<"Hapazard Movement"<<endl;
        }

        void attackAction(void)
        {
             cout<<"Firing Strategy "<<strategyId<<endl;
            moveAction();
        }

        void defendAction(void)
        {
             cout<<"Duck!"<<endl; 
        }
};


//Smart Enum
//It look's like an enum, but names are not representing a number
//They are representing an object
class TankModes
{
    public:
    static ITankActionMode *Aggresive;
    static ITankActionMode *Defensive;
    static ITankActionMode *Gurilla;
    static ITankActionMode *GurillaStrategy(int strategy){
        return new GurillaActionMode(strategy);
    }
        
};
