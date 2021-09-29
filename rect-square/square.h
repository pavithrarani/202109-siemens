#pragma once
#include "rectangle.h"
#include <exception>
#include "proper-rectangle.h"

using namespace std;

class RSquare: public TwoTileRectangle{
        
   

    public:
        RSquare(int size): TwoTileRectangle(size,size){}

    Orientation orientation() {
        
        //return Orientation::Sleeping;
        //throw "Orientation is not supported";

        throw "Orientation is not supported";
       
    }  
        
};


class Square :  public Rectangle
{
        int size;
    public:
        Square(int size):size(size){}
        int area()const{return size*size;}
        int perimeter()const {return size*4;}
        void draw(){cout<<"Square["<<size<<"] drawn"<<endl;}
};









