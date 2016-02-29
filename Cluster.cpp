//
// Created by Catie Cook on 2/17/16.
//


#include <cassert>
#include <sstream>
#include "Cluster.h"
#include "Point.h"


namespace Clustering {

//default constructor

    Cluster::Cluster() {
        __size = 0;
        __points = nullptr;
    }


    LNode::LNode(const Point &point, LNodePtr a) {
        Point p(point);
        LNodePtr another(a);
    }


    void Cluster::__del() { }

    bool Cluster::__in(const Point &p) const

    {
        return false;
    }

    void Cluster::__cpy(LNodePtr pts) { }

    //Cluster::Cluster() { }

//    Cluster::~Cluster() { __del; }

    Cluster::Cluster(const Cluster &c)
    {

        for (int i = 0; i <c.getSize(); ++i) //iterates till = size
        {
            add(c[i]);
        }
    }


    int Cluster::getSize() const
    {

        return __size;
    }

    void Cluster::add(const Point &point) {

        LNodePtr a = new LNode(Point(point), nullptr);  //create a new node and point to the head
        if (__points == nullptr)
        {
            __points = a;
        }
        else if (__points->point > point)  //attach a new value into the front, disconnect the ptr and reassign it to point to the new front
        {
            a->next = __points; //always point the new node first, and then disconnect the corresponding pointer to the new node so the linked list works
            __points = a;
        }
        else {
            //find the right spot
            LNodePtr c = __points, n = __points->next;
            while (true) {
                if (n == nullptr || n->point > point) {
                    c->next = a->next = n;
                    break;
                }
                else {
                    c = n;
                    n = n->next;
                }
            }
        }
        __size++;  //keep up with number of points
    }
    const Point &Cluster::remove(const Point &ptr)
    {
        //if no points exist
        //assert(const Point &ptr)
        LNodePtr c;
        LNodePtr pre = nullptr;

        LNodePtr c = __points; //n = __points->next; //n is = to the pint after __ppoints aka next node

        while (c != nullptr) {

            if (c->point == ptr)  //the point was found
            {
                if (pre == nullptr)
                {
                    __points = c->next; //the c (next) local pointer points to the next node
                }
                //LNodePtr del = c;
                //c->next == c->next; //point current to the next and delete
                delete c;

                --__size; //decrements size one so we keep track of current size

                break;
            }
        }
        pre = c;
        c = c->next; //c is a ptf now pointing to the new current node which is the old next node

        return ptr;
    }


    bool Cluster::contains(const Point &point) {

        LNodePtr c = __points; //same as previous declaration

        if(c != nullptr)
        {
            if (c->point.getId() == point.getId()) {
                return true;
            }
            else
                c = c->next;
        }

        return false; //all of the if statements skipped, return = false
    }

    // FRIENDS

    //COMPARING

    bool operator!=(const Cluster &lhclus, const Cluster &rhclus) //test for non-equality
    {
        return (rhclus != lhclus);
    }

    bool operator==(const Cluster &lhclus, const Cluster &rhclus) //test for equality
    {
        if (rhclus.getSize() != lhclus.getSize())
            return false; //not equal

        for (int i = 0; i< lhclus.getSize(); ++i)
        {
            if (lhclus[i] != rhclus[i])
                return false; //tests for equality through cluster nodes and returns false if it finds nonequality
        }
        return true; //if all are equal it returns true
    }

    //SUBSRIPT

    const Point &Cluster::operator[](unsigned int index) const
    {
        assert (__size > 0); //if size is less than 0 program exits
        LNodePtr cursor = __points; //the cursor will go through points

        for(int i=0; i < index; ++i)
        {
            cursor = cursor->next; //the cursor is now points to next node
        }
        return cursor->point; //point to and dereference to return the current point cursor points to
    }

    // ARITHMETIC
    Cluster &Cluster::operator+=(const Point &point) //need to use the add function instead
    {
        add(point);

        return *this; //returns object from add
    }

    Cluster &Cluster::operator-=(const Point &point) //I need to use the remove function instead
    {
        remove(point);

        return *this;
    }

    Cluster &Cluster::operator+=(const Cluster &rclus)
    {
       for(int i = 0; i < rclus.getSize(); ++i)
        {
            add(rclus[i]);  //add clusters together to make one
        }

        return *this;
    }

    Cluster &Cluster::operator-=(const Cluster &rclus)  //literally the same but with remove instead of add
    {
        for(int i = 0; i < rclus.getSize(); ++i)
        {
            remove(rclus[i]);
        }

        return *this;
    }

//    Cluster &Cluster::operator=(const Cluster &cluster)
//    {
//
//
//    }

    friend const Cluster operator+(const Cluster &lhclus, const Point &rhpt)
    {
        Cluster added(lhclus);
        added += rhpt;

        return added;
    }

    friend const Cluster operator-(const Cluster &lhclus, const Point &rhpt)
    {
        Cluster difference(lhclus);
        difference -= rhpt;

        return difference;
    }

   const Cluster operator-(const Cluster &lhclus, const Cluster &rhclus) // (asymmetric) difference //
   {
       Cluster difference(lhclus);
        difference -= rhclus;

        return difference;
   }

    const Cluster operator+(const Cluster &lhclus, const Cluster &rhclus) // union
    {
    Cluster added(lhclus); //new cluster with constructor copied from lhclus
    added -= rhclus;

    return added;
    }

 // INSERTION AND EXTRACTION OPERATORS

    std::ostream &operator<<(std::ostream &out, const Cluster &c)
    {
        for (int i = 0; i < c.getSize(); ++i)
        {
            out << c[i];
        }
    }


    std::istream &operator>>(std::istream &in, Cluster &c)
    {
        while (!in.eof())
        {
            Point p(1);

            std::string line;
            std::getline(in, line);

            if(line.length() > 0)
            {
                std::stringstream ss(line);
                ss >> p;
                c.add(p);
            }
        }
    }


}