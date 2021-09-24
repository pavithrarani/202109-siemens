#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define PI 3.141592653589


class Shape
{
    public:
    virtual double area() const=0;
    virtual double perimeter() const=0;
    virtual void draw() const=0;
};

class Circle:public Shape
{
    double radius;

public:
    Circle(double radius)
    {
        this->radius = radius;
    }

    double area() const
    {
        double a = 0;
        a = PI * radius * radius;
        return a;
    }

    double perimeter() const
    {

        double p = 0;

        p = 2 * PI * radius;

        return p;
    }

    void draw(void) const
    {
        cout << "Circle(" << radius << ")" << endl;
    }
};

class Rectangle:public Shape
{
    double width, height;

public:
    Rectangle(double width, double height)
    {
        //initialize fields
        this->width = width;
        this->height = height;
    }

    double area() const
    {
        double a = 0;
        a = width * height;
        return a;
    }

    double perimeter() const
    {

        double p = 0;
        p = 2 * (width + height);

        return p;
    }

    void draw(void) const
    {
        cout << "Rectangle[" << width << "," << height << "]" << endl;
    }
};

class Triangle:public Shape{
    double s1,s2,s3;
    public:
    double area() const {
        double s=perimeter()/2;
        return sqrt(s*(s-s1)*(s-s1)*(s-s3));
    }

    double perimeter() const{return s1+s2+s3;}

    void draw() const{
         cout<<"Triangle<"<<s1<<","<<s2<<","<<s3<<">"<<endl;
    }
}