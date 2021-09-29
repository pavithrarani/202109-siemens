#pragma once
#include <iostream>
using namespace std;
#include "rectangle.h"
#include "orientation.h"




class ProperRectangle : public Rectangle
{
    int width,height;
    public:
    ProperRectangle(int width,int height){
        this->width = width;
        this->height = height;
    }

    int area() const { return width*height; }
   
    int perimeter() const  {return 2*(width+height);}
    virtual void setWidth(int width) {this->width=width;}
    virtual void setHeight(int height) {this->height=height;}
   
    void draw(){
        cout<<"ProperRectangle ["<<width<<","<<height<<"] drawn"<<endl;
    }
  
    virtual Orientation orientation(){
        if(width>height){
            return Orientation::Sleeping;
        } else{
            return Orientation::Standing;
        }
    }
};