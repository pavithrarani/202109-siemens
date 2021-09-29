#pragma once
#include <iostream>
#include "rectangle.h"
#include "proper-rectangle.h"
#include "twotile-rectangle.h"
#include "square.h"

using namespace std;

class RectangleCreator
{
    
    public:
        static Rectangle * create(double x, double y){
            if(x==y)
                return new Square(x);
            else
                return new ProperRectangle(x,y);
        }

        static Rectangle * createSquare(double x){
            return new Square(x);
        }
};

class RectangleFactory
{
    public:
    virtual Rectangle * create(double x, double y)=0;
};


class RectangleSquareFactory: public RectangleFactory
{
    public:
    virtual Rectangle * create(double x, double y){
            if(x==y)
                return new Square(x);
            else
                return new ProperRectangle(x,y);
    }
};



class RectangleSquareTwoTileRectangleFactory: public RectangleFactory
{
    RectangleSquareFactory old;

    public:
    virtual Rectangle * create(double x, double y){
            if(x==2* y || y== 2*x)
                return new TwoTileRectangle(x,y);
            else
                return old.create(x,y);
                             
    }
};


