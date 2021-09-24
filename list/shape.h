#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define PI 3.141592653589
enum ShapeType{Circle,Rectangle};

class Shape
{
    //fields
        double radius;
        double width,height;
        ShapeType type;
    
    public:
        Shape(double width, double height){
            //initialize fields
            this->width = width;
            this->height = height;
            this->type = ShapeType::Rectangle;
        }

        Shape(double radius){
            this->radius = radius;
            this->type = ShapeType::Circle;
        }

        double area() const {
            double area=0;
            switch(type){
                case ShapeType::Circle:
                    area=PI*radius*radius;
                    break;
                case ShapeType::Rectangle:
                    area=width*height;
            }
        }
        double perimeter() const {

            double area=0;
            switch(type){
                case ShapeType::Circle:
                    area=2*PI*radius;
                    break;
                case ShapeType::Rectangle:
                    area=2*(width+height);
            }
        }

        void draw(void)
        {
            if(type==ShapeType::Circle)
                cout<<"Circle("<<radius<<")"<<endl;
            else
                cout<<"Rectangle["<<width<<","<<height<<"]"<<endl;
            //return result;
        }

        string getType(void)
        {
            if(type==ShapeType::Circle)
                return "circle";
            else
                return "rectangle";
            
        }
        
};