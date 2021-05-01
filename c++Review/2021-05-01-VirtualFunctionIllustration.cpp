// CPP program to illustrate working of Virtual Functions
#include <iostream>
using namespace std;

class base{
    public:
        void fun_1() {cout << "base-1" << endl; }
        virtual void fun_2() {cout << "base-2" << endl;}
        virtual void fun_3() {cout << "base-3" << endl;}
        virtual void fun_4() {cout << "base-4" << endl;}

};
class derived : public base{
    public:
        void fun_1() { cout << "derived-1" << endl;}
        void fun_2() { cout << "derived-2" << endl;}
        // void fun_3() { cout << "derived-3" << endl;}
        void fun_4(int x) { cout << "derived-4" << endl;}
};
int main(){
    base* p;
    derived obj1;
    p = &obj1;

    // Early binding because fun1 () is non-virtual in base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    // Early binding but this function call is illegal(produces error) becasue pointer
    // is of base type and function is of derived class
    p->fun_4(5);


    /*Result:
    base-1
    derived-2
    base-3
    base-4
    */
}