// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
class base
{
    public:
        virtual void print()
        {cout << "print base class" << endl;}

        void show()
        {cout << "show base class" << endl;}

        /* error: constructor for 'derived' must explicitly initialize 
        the base class 'base' which does not have a default constructor
        virtual base()
        {cout << "This is base constructor" << endl;}*/
        base()
        {cout << "This is base constructor" << endl;}

        virtual ~base()
        {cout << "This is base destructor" << endl;}
};
class derived : public base{
    public:
        void print() //print () is already virtual function
        { cout << "print derived class" << endl;}

        void show()
        { cout << "show derived class" << endl;}

        derived()
        {cout << "This is derived constructor" << endl;}

        ~derived()
        {cout << "This is derived destructor" << endl;}
};
int main(){
    base *bptr;
    derived d;
    bptr = &d;

    // Virtual function, binded at runtime (Runtime polymorphism)
    // bptr->print();

    // Non-virtual function, binded at compile time
    // bptr->show();

    return 0;
}