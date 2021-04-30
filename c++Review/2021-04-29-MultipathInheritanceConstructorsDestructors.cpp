#include <iostream>
using namespace std;
// This code is a implementation for Multipath inheritance problem
// Articles from https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/
// Articles from https://www.geeksforgeeks.org/inheritance-in-c/

class A{
    public:
        int id_A;
        A(){
            cout << "Constructor A" << endl;
        }
        ~A(){
            cout << "Destructor A" << endl;
        }
};
// class B : virtual public A{
//     public:
//         int id_B;
// };
class B : virtual public A{ 
    public:
        int id_C;
        B(){
            cout << "Constructor B" << endl;
        }
        ~B(){
            cout << "Destructor B" << endl;
        }
};
// by adding virtual we may avoiding ambiguity using virtual base class
// class C : virtual public A{ 
//     public:
//         int id_C;
// };
class C : virtual public A{ 
    public:
        int id_C;
        C(){
            cout << "Constructor C" << endl;
        }
        ~C(){
            cout << "Destructor C" << endl;
        }
};
class D : public B, public C{
    public:
        int id_D;
        D(){
            cout << "Constructor D" << endl;
        }
        ~D(){
            cout << "Destructor D" << endl;
        }
};
int main(){
    D obj_D;
    //
    /* Without Virtual
    Constructor A
    Constructor B
    Constructor A
    Constructor C
    Constructor D
    Destructor D
    Destructor C
    Destructor A
    Destructor B
    Destructor A*/
    /* With Virtual
    Constructor A
    Constructor B
    Constructor C
    Constructor D
    Destructor D
    Destructor C
    Destructor B
    Destructor A
    */
}