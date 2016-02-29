#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef struct LNode *LNodePtr; // anywhere the compiler sees LNodePtr it knows its a points to a struct called LNode

    struct LNode {

        Point point;
        LNodePtr next;

        LNode(const Point &point, LNodePtr a);

    };

    class Cluster {

        int __size; //must always be in sync to number of Points
        LNodePtr __points; //empty cluster at the very least pints should be set to "" which is a null point

// ****** SAYS IN INSTRUCTIONS THESE ARE OPTIONAL ******
//        void __del(); // only write this once
//        void __cpy(LNodePtr pts);
//        bool __in(const Point &p) const;


    public:
        Cluster(); //default constructor

        // The big three: cpy ctor, overloaded operator=, dtor ***IMPORTANT****
        Cluster(const Cluster &c);

        // constructor
        Cluster &operator=(const Cluster &c); //assignment operator  - find this in lecture 7, but have to change it a bit because the points are static in here and in the lecture they are poiners
        ~Cluster() {} ; //destructor

        // Getters/setters
        int getSize() const; // TODO add to the requirements

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const Point &p); // TODO add asc order to the requirements this // adds a point or cluster
        const Point &remove(const Point &p); //will return a const point reference // removes a point
        bool contains(const Point &p);

        // Overloaded operators

        // Members: Subscript
        const Point &operator[](unsigned int index) const; // notice: const

        // Members: Compound assignment (Point argument)
        Cluster &operator+=(const Point &c); // friends are non member functions that have access to private functions
        Cluster &operator-=(const Point &c); // why we overload this way:

        // Members: Compound assignment (Cluster argument) //These are BINARY
        Cluster &operator+=(const Cluster &c); // union // sets can only have one copy of every item, if there is a union of two sets that have duplicate opjects, it will automatically only keep one copy of duplicate in union
        Cluster &operator-=(const Cluster &c); // (asymmetric) difference  // this will hold only the contents that are not common between the two sets. So, C1 -= C2 will hold only the unique pieces of C1, while C2 -= C1 will be only the unique contents on C2

        // Friends: IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &); //this will read in lines from the file so we can clean it up

        // Friends: Comparison
        friend bool operator==(const Cluster &c, const Cluster &c2); // equality if they have the same points then they are equal
        friend bool operator!=(const Cluster &c, const Cluster &c2); //non equality

        // Friends: Arithmetic (Cluster and Point)
        friend const Cluster operator+(const Cluster &c, const Point &p2);
        friend const Cluster operator-(const Cluster &c, const Point &p2);

        // Friends: Arithmetic (two Clusters)
        friend const Cluster operator+(const Cluster &c, const Cluster &c2); // union
        friend const Cluster operator-(const Cluster &c, const Cluster &c2); // (asymmetric) difference // C1 - C2 and C2 - C1

    };

}
#endif //CLUSTERING_CLUSTER_H



//IN cluster.cpp each point will have to be in a NODE

/*
int Cluster::getSize() const
{
    return __size;
}

void Cluster::add(const Point &)
{
    LNodePtr a = new LNode(Point(p), nullptr);  //create a new node and point to the head
    if (__points == nullptr) {
        __points = a;
    }
    else if (__points->point >p)  //attach a new value into the front, disconnect the ptr and reassign it to point to the new front
    {
        a->next = __points; //always point the new node first, and then disconnect the corresponding pointer to the new node so the linked list works
        __points = a;
    }
    else {
        //find the right spot
        LNodePtr c = __points, n = __points->next;
        while (true) {
            if (n == nullptr || n->point > p) {
                c->next = aa->next = n;
                break;
            }
            else {
                c = n
                n = n->next;
            }
        }
    }
    size++;
}

const Point& Cluster::remove(const Point &) //Make sure you locate the node to delete, you need two pointers that follow eachother. "Previous" and "Current/Delete"  prev->next = del->next; delete del; (use the this pinter to point the pointer to the pointer that is pointing to the correct node.
{
    return Point;
}


 #include <cassert>

 if (__size == 0)
 {
 assert(!__points); //should be a null ptr for __points
 }

 //assert will fail if __points is false
 //this will tell you exactly what assertion failed at exit compilation
//assert is used to test conditions that I know should be true.
 */