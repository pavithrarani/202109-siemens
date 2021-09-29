#pragma once
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.141592653589

class Point
{
private:
    double x, y;

    Point(double x, double y)
    {
        cerr << "DEBUG: Point Created (" << x << "," << y << ")" << endl;
        this->x = x;
        this->y = y;
    }

public:
    double X() { return x; }
    double Y() { return y; }

    double R()
    {
        return sqrt(x * x + y * y);
    }

    double Theta()
    {
        double rad = atan(y / x); //radian value
        return rad * 180 / PI;
    }

    static Point* getPolar(double r, double thetaDeg)
    {
        double theta = thetaDeg * PI / 180;
        double x = r * cos(theta);
        double y = r * sin(theta);

        return getPoint(x,y);
    }

    static Point *getCartisian(double x, double y){
        return getPoint(x,y);
    }
    private:
    static vector<Point*> cache;
    static Point * getPoint(double x, double y){

        for(Point * existing : cache){
            if(existing->x==x && existing->y==y)
                return existing;
        }

        Point * newPoint=new Point(x,y);
        cache.push_back(newPoint);
        return newPoint;
    }
};
