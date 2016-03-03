//
// Created by Catie Cook on 2/17/16.
//
#include "Point.h"

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>


namespace Clustering {


    unsigned int Point::__idGen = 0; // id generator

    //constructors
    Point::Point(int i)
    {
        __id = __idGen;
        ++__idGen; // increment IDs  as they are created

        __dim = i;
        __values = new double[__dim]; //array of doubles for ids

        for (int j = 0; j < __dim; ++j)
        {
            __values[j] = 0;
        }
    }


    // **** BIG THREE ******
    // CPY CONST
    Point::Point(int i, double *pDouble)  //not necessary to use this constructor
    {
        __id = __idGen;
        ++__idGen; // increment IDs  as they are created

        __dim = i; //create array with dims
        __values = new double[__dim];
        for (int j = 0; j < __dim; j++)
        {
            __values[j] = pDouble[j]; //fill the array with the dimemsions/data
        }

    }

    Point::Point(const Point &p)
    {
        __dim = p.__dim;
        __values = new double[__dim]; //values is equal to an array of __dim dimensions
        __id = p.__id; //applying the private member functions here

        for (int i = 0; i < __dim; i++)
        {
            __values[i] = p.__values[i]; //copying over values into new array until __dim is run through
        }

    }

    // OVERLOADED =
    Point &Point::operator=(const Point &p)
    {
        if (this != &p)
        {
            __dim = p.__dim;
            __id = p.__id;
        }

        if (__values != nullptr)
            delete[] __values;

        __values = new double[__dim];

        for (int i = 0; i < __dim; ++i)
        {
            __values[i] = p.__values[i];

        }
        return *this;
    }
    // DESTRUCT
    Point::~Point()
    {
        delete [] __values;
    }

    int Point::getDims() const {
        return __dim;
    }

    int Point::getId() const
    {
        return __id;
    }

    // **** DISTANCT TO FUNCTION ******

    double Point::distanceTo(const Point &point) const
    {
        double sum = 0;
        double distance = 0;

        for (int i = 0; i < point.__dim; i++)
        {
            sum += pow(point.__values - this->__values, 2);
            distance = sqrt(sum);

        } //The values pointed to in point.
        return distance;
    }

    // ******** OVERLOADED OPERATORS ******

    Point &Point::operator*=(double d)  // p *= 6; p.operator*=(6); //use for or while loop to multiply every point by the double
    {
        for(int i = 0; i < __dim; ++i)
        {
            __values[i] *= d;
        }
        return *this;
    }

    Point &Point::operator/=(double d) //use for or while loop to multiply every point by the double
    {
        for(int i = 0; i < __dim; ++i)
        {
            __values[i] /= d;
        }
        return *this;
    }

    const Point Point::operator*(double d) const
    {
        Point p(*this);
        p *= d; //p = d*p

        return p;
    }

    const Point Point::operator/(double d) const
    {
        Point p(*this);
        p /= d;

        return p;
    }

    double &Point::operator[](int index)
    {

         return __values[index];
    }


    //friends

    Point &operator+=(Point &point, const Point &point1)
    {
        for (int i = 0; i < point; ++i)
        {
            point[i] += point1.getValue(i);

        }
        return point;
    }

    Point &operator-=(Point &point, const Point &point1)
    {
        for (int i = 0; i < point; ++i)
        {
            point[i] -= point1.getValue(i);

        }
        return point;
    }

    const Point operator+(const Point &point, const Point &point1) //defined this in class as an example
    {
        Point point3(point);
        point3 += point1;
        return point3;
    }

    const Point operator-(const Point &point, const Point &point1)
    {
        Point point3(point);
        point3 -= point1;
        return point3;
    }

    bool operator==(const Point &point, const Point &point1)
    {
        if (point.__id == point1.__id)
        {
            return true;
        }
        else
            return false;
    }

    bool operator!=(const Point & point, const Point & point1)

    {
            if (point != point1)
            {
                return true;
            }

            else
                return false;
    }

    bool operator>(const Point & point, const Point & point1)
    {

        if(point > point1)
        {
            return point > point1;
        }
        else
            return false;
    }

   bool operator<(const Point & point, const Point & point1)
    {
       //Point point(), point1();

        if(point < point1)
        {
            return point < point1;
        }
        else
            return false;
    }

    bool operator<=(const Point &point, const Point &point1)
    {
       return !(point < point1);
    }

    bool operator>=(const Point &point, const Point &point1)
    {
        return  !(point > point1);

    }
    std::ostream &operator<<(std::ostream &out, const Point &point) //module 3 lesson 11
    {

        int i = 0;
        for ( ; i < point.__dim - 1; i++)
        {
            out << point.__values[i] << ", ";
        }
        out << point.__values[i];

        return out;
    }


    std::istream &operator>>(std::istream &in, Point & point) // find code for this in lesson 11.
    {

        std::string line;

        std::getline(in, line);
        int length = std::count(line.begin(), line.end(), ',') + 1;


        std::stringstream ss(line);
        int i = 0;

        while (getline(in, line)) //while there are lines to read
        {
            std::string vals;
            getline(ss, vals, ',');

            std::stringstream valstream(vals);

            valstream >> point.__values[i];

            i++;
       }


    return in;
    }


    void Point::setValue(int i, double d)
    {
        if (i >= 0 && i < __dim)
        {
            __values[i-1] = d;
        }
    }
    double Point::getValue(int d) const
    {
    if (d >= 0 && d <__dim)
        return __values[d];
        else
        return 0;
    }

}//end of point.cpp




/*

 class Point {
    double a, b;
 public:
    Point () : Point (0, 0) {}
    Pint (double a, double b) : a(a), b(b) {} //the a outside the bracket is always going to be a member and inside will be argument so compiler knows which is which AKA no ambiguity

    double getA() const; { return a; }
    double getB() const; { return b; }
    void setA(double a) { this->a = a; } //the this pointer is the pointer to the current object point. When implimenting something you can use 'this' to point to the current value without explicitly setting it
    void setB(double b) { this ->b = b; } //this is equiv to (*this).a the pointer dereferences and points to it at once

     friend ostream @operator<<(ostream @os, const Point &p);
     };

     friend ostream @operator<<(ostream &os, const Point &p)
    {
    os <<  p.a << ", " << p.b << endl;

    return os;
    }



 TEMPLATES


 template <typename T> // the name doens't matter, just has to be something

 class Point {
    T a, b;
 public:
    Point () : Point (0, 0) {}
    Pint (T a, T b) : a(a), b(b) {} //the a outside the bracket is always going to be a member and inside will be argument so compiler knows which is which AKA no ambiguity

    T getA() const; { return a; }
    T getB() const; { return b; }
    void setA(double a) { this->a = a; } //the this pointer is the pointer to the current object point. When implimenting something you can use 'this' to point to the current value without explicitly setting it
    void setB(double b) { this ->b = b; } //this is equiv to (*this).a the pointer dereferences and points to it at once


    template <typename S>
     friend ostream @operator<<(ostream @os, const Point<S> &p);
     };

      template <typename W>
     friend ostream @operator<<(ostream &os, const Point<W> &p)
    {
    os <<  p.a << ", " << p.b << endl;

    return os;
    }

    int main () {
    cout << "Hellow World!" << endl;

    Point <double> p(6.7, 8.3);
    Point <int> point(6, 3);
    Point<std::string> spoint("one", "two")

 cout << p << endl;
 cout << point << endl;
 cout << spoint << endl;  //all types should work if the functionality of the template is correct









  template <typename T> // the name doens't matter, just has to be something

 class Point {
    int __dim;
    T *__values;

 public:
    Point (int dim) :
        __dim(dim),
        __values(new T[__dim])
        {}


    T getValue() const; { return __values[i]; }

    void setValue( int i, T a ) { values[i] = a; } //the this pointer is the pointer to the current object point. When implimenting something you can use 'this' to point to the current value without explicitly setting it
    void setB(double b) { this ->b = b; } //this is equiv to (*this).a the pointer dereferences and points to it at once

    T &operator[] (int i) { return __values[i]}

    template <typename S>
     friend ostream @operator<<(ostream @os, const Point<S> &p);
     };

 */


