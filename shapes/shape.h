#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define PI 3.141592653589


enum ShapeType{Circle,
Rectangle,
Square,
Triangle   //OCP x1
}; 

class Shape
{
    //fields
    double radius;
    double width,height;
    ShapeType type;
    double s1,s2,s3;  //OCP x2 ---> increases size of Circle and Rectangle
    double side;
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

        Shape(double side){
            this->side=side;
            this->type=ShapeType::Square;
        }


        //OCP x3
        Shape(double s1, double s2, double s3){
            this->s1 = s1;
            this->s2= s2;
            this->s3= s3;
            this->type = ShapeType::Triangle;
        }
        //OCP x4
        double area() const {
            double a=0;
            double s;
            switch(type){
                case ShapeType::Triangle:
                    s=perimeter()/2;
                    a=sqrt(s*(s-s1)*(s-s2)*(s-s3));
                    break;
                case ShapeType::Circle:
                    a=PI*radius*radius;
                    break;
                case ShapeType::Rectangle:
                    a=width*height;
                
            }
            return a;
        }


        //OCPx5
        double perimeter() const {

            double p=0;
            switch(type){                
                case ShapeType::Circle:
                    p=2*PI*radius;
                    break;
                case ShapeType::Rectangle:
                    p=2*(width+height);
                case ShapeType::Triangle:
                    p=s1+s2+s3;
            }

            return p;
        }

        //OCPx6

        void draw(void)
        {
            if(type==ShapeType::Triangle)
                cout<<"Triangle<"<<s1<<","<<s2<<","<<s3<<">"<<endl;

            if(type==ShapeType::Circle)
                cout<<"Circle("<<radius<<")"<<endl;
            else
                cout<<"Rectangle["<<width<<","<<height<<"]"<<endl;
            //return result;
        }


        //OCPx7
        string getType(void)
        {
            if(type==ShapeType::Circle)
                return "Circle";
            else if(type==ShapeType::Triangle){
                return "Triangle";
            }
            else
                return "Rectangle";
            
        }
        
};