#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
        unsigned int __id;
        int __dim;        // number of dimensions of the point
        double *__values; // values of the point's dimensions *Does not point untill it is initialized . It is an array

        static unsigned int __idGen; // id generator sets the ID // static variables mean it belongs to the class not the object
//The objects do not get their own copy of this static variable
    public:
        // Point(); //Point p; Point arrayOfPoints[300]; //This would be the default constructor DO NOT INITIATE
        Point(int); //the int is the value that we will assign in the constructor to __dim
        //Point anotherArray(10)[100] - - this will not compile you have to do it this way
        // Point **point = new Point*[100]; this is for allocating a pointer to an array of pointers
        Point(int, double *); //This is not a necesisary constructor. Only if I want to use it

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators
        int getId() const;
        int getDims() const;
        void setValue(int, double); //two arguments because
        double getValue(int) const;

        // Functions
        double distanceTo(const Point &) const; //works for multip dimentional points

        // Overloaded operators

        // Members = arithematic with doubles
        Point &operator*=(double); // p *= 6; p.operator*=(6);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1 * 2) = p2, will return a pint by value ; The const prevents assigning a new value to a value with no handle/address
        const Point operator/(double) const; // p3 = p2 / 2;

        double &operator[](int index); //subscript operator allows you to access specific locations in array and set it to other values, instead of having to step through the array

        // Friends - arithmatic with points
        //WHY THEY ARE FRIENDS: three ways to overload an operator.
        friend Point &operator+=(Point &, const Point &); //this one can be changed and a reference will be returned
        friend Point &operator-=(Point &, const Point &);//the pass by reference is giving access to the actual objects, not copies.
        friend bool operator>(const Point &, const Point &); //if pass by reference is const, don't mess with them
        friend const Point operator+(const Point &, const Point &); //object is created inside this operator, new object is returned. And object must be declaired inside this function
        friend const Point operator-(const Point &, const Point &); //Same same. This function creates a new pbject by subtracting the two pints it takes in
        /*Example:
        // const Point op+(lhs, rhs) { //takes in two points
         Point p(lhs); //copy constructor called
         p+=rhs;
         return p;
        */

        friend bool operator==(const Point &, const Point &); //if there is no pass by reference, it is a copy, so it takes up more space. Try to avoid.
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &); //extraction operator allows me to read in a point from a line

        // We will order the numbers in lexical graphic order (aka in order of size) the larger numbers go under the smaller
        // Compare the positions from left to right, the left is most significant
        //
    };

}
#endif //CLUSTERING_POINT_H

/*
 *  Class::idGen
 *  idGen sets the first point's ID to 0
 *  then it increments every time a new object is created
 *  When we are testing for equality (==) we check all values, and all of the ID's. Just because they have the same points in the object, it does not mean they are taking up the same space
 *  This is implemented in the constructor
 *  DO NOT implement in copy constructor or Assignment Operator (this will cause program to fail some tests)
 *
 *  We will be using the copy constructor to create new NODES
 *  EXAMPLE:
 *  LNode::LNode(LNode ptr, const Point &p)
 *  next(null_ptr)
 *  point(p)
 *
 *
 *
 *
 *  NAMESPACES: named scope
 *  whatever is inside braces is a scope
 *  namespace is a named scope that starts when you declair the namespace, and ends when you close its brace
 */