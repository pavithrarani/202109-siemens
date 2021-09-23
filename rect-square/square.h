#pragma once
#include "rectangle.h"
#include "shape.h"

class RSquare: public ProperRectangle{
    public:
        RSquare(int size): ProperRectangle(size,size){}
        
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









