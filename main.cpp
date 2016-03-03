// main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ErrorContext.h"
#include "ClusteringTests.h"


using std::cout;
using std::endl;

using namespace Testing;

int main() {

    const int NumIters = 3;

    cout << endl << "Testing PA2!!" << endl << endl;

    cout << "NOTE:  If you see any memory errors, you MUST fix them!" << endl;
    cout << "       Tests intentionally invoke destructors after they complete,"
    << endl;
    cout << "       so if you see a seg-fault after a passed test, it is"
    << endl;
    cout << "       probably a bug in your destructor." << endl;

    cout << endl;

    ErrorContext ec(cout);

    // point tests **** Test funtions one at a time *******
    test_point_smoketest(ec);
    test_point_id(ec, NumIters);
    test_point_getsetelem(ec, NumIters);
    test_point_copying(ec, NumIters);
    test_point_assignment(ec, NumIters);
    test_point_equality(ec, NumIters);
    test_point_comparison(ec, NumIters);
    test_point_CAO(ec, NumIters);
    test_point_SAO(ec, NumIters);
    test_point_distance(ec, NumIters);
    test_point_IO(ec, NumIters);

//   cluster tests
    test_cluster_smoketest(ec);
    test_cluster_subscript(ec, NumIters);
    test_cluster_equality(ec, NumIters);
    test_cluster_order(ec, NumIters);
    test_cluster_addremove(ec, NumIters);
    test_cluster_contain(ec, NumIters);
    test_cluster_copying(ec, NumIters);
    test_cluster_assignment(ec, NumIters);
    test_cluster_CAO(ec, NumIters);
    test_cluster_SAO(ec, NumIters);
    test_cluster_IO(ec, NumIters);

/*
    //************ EXAMPLES FROM CLASS **************

    Clustering::Point p1(10), p2(10); //10 value pint
    p1.setValue(5, 5.6); //sets the values
    p1[7] = 3.4; //implementing the operator

    Cluster::Point p3(10);
    p3 = p1 + p2; // the values in p1 and p2 will be added and p3 is that new value
    p3 = p1 * 2; //double the dimension
    p3 = p2 / 3; //divide the dimension

    p3 += p1; //adds p1 to p3 and making that the new value of p3
    p3 -= p2; //subtracts p2 from p3

    Cluster::Point p4(10), p5(10);

    for (int i = 0; i < 10; i++) //this fills both arrays entirely
    {
        p4[i] = 1.2;
        p5[i] = 5.6;
    }
    bool p4largerthanp5 = p4 > p5; //this is a comparison opperator, testing to see if p4 is bigger than p5 and then sending true is it is

    cout << p4largerthanp5 << endl; //we set the p4 to 1.2 and p5 is 5.6 everywhere so it should return false

    p4[0] = 10.2;

    p4largerthanp5 = p4 > p5;

    cout << endl << endl;

    cout << (p4 > p5) << endl;
    cout << (p4 >= p5) << endl;
    cout << (p4 < p5) << endl;
    cout << (p4 <= p5) << endl; //notice = goes AFTER the < or > symbols
    cout << (p4 == p5) << endl;

    //these two are equivilant
    cout << (p4 !=  p5) << endl;
    cout << operator !=(p4, p5) << endl;



MODULE 2 LECTURE 7 has an example of how to use the &operator=(cont Cluster &rhs) style function

 //Automatic Point Conversion

 Clustering::Point p7(10), p8(10); //This will make compiler find the correct member function and figure out how to convert an integer to a point.

 CLustering:: Point p9 = p7 + 10; //uses overloaded + operator to add this and assign the new point called p9

 p9.operator+(p8,p7);

 Clustering::Point p10 = 10+p8; // This does not work because the integer is first. make sure calls are identical to declaration
 (p7+p8) = p10; //this is incorrect, it tries to change constant points.
 p10 = (p7 + p8); //this is the correct way because it assigns the value to a temporary (non const) point.

 //left hand side is always the calling side.

 //how to implement the + operator

 definition: op+(const Point &);
 call: p3 = p1 + p2; //the compiler automatically knows that the p1 is preforming the op+ overloading on the second object aka p2 here.
 same as: p3 = p1.op+(p2);


    */
    return 0;
}


/*
  bool op < (lhs, rhs);
  bool op > (lhs, rhs);

  return (rhs < lhs);

 */