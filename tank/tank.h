#pragma once
#include <iostream>
using namespace std;

enum TankMode
{
    Aggresive,
    Passive,
    Gurrilla
};

class Tank
{
    //fields
    TankMode mode;      
    
    public:
        Tank(TankMode mode=TankMode::Aggresive){
            //initialize fields
            this->mode=mode;
        }
        //Methods
        void setMode(TankMode mode){
            this->mode=mode;
        }
        void move(void)
        {
            switch(mode)
            {
                case TankMode::Aggresive:
                    cout<<"Move Towards Enemy"<<endl;
                    break;
                case TankMode::Passive:
                    cout<<"Move Away from Enemy"<<endl;
                    break;
                case TankMode::Gurrilla:
                    cout<<"Hapazard Movement"<<endl;
                    break;
            }            
        }

        void attack(void)
        {
            switch(mode)
            {
                case TankMode::Aggresive:
                    cout<<"Fire at Enemy"<<endl;
                    break;
                case TankMode::Passive:
                    cout<<"Hold Fire"<<endl;
                    break;
                case TankMode::Gurrilla:
                    cout<<"Fire"<<endl;
                    move();
                    break;
            }            
        }

        void defend(void)
        {
            switch(mode)
            {
                case TankMode::Aggresive:
                    cout<<"Cover Fire"<<endl;
                    break;
                case TankMode::Passive:
                    cout<<"Hide"<<endl;
                    break;
                case TankMode::Gurrilla:
                    cout<<"Duck!"<<endl;                    
                    break;
            }            
        }
};