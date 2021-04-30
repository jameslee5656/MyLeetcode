#include <iostream>
using namespace std;
// This code is a implementation for Multipath inheritance problem
// Articles from https://www.geeksforgeeks.org/inheritance-in-c/
class A{
    public:
        int id_A;
};
class B : virtual public A{
    public:
        int id_B;
};
// class C : public A{ 
//     public:
//         int id_C;
// };
// by adding virtual we may avoiding ambiguity using virtual base class
class C : virtual public A{ 
    public:
        int id_C;
};
class D : public B, public C{
    public:
        int id_D;
};
int main(){
    D obj_D;
    // obj_D.id_A = 10; //  error: non-static member 'id_A' found in multiple base-class subobjects of type 'A':
    // obj_D.B::id_A = 10; specify which path we are going
    // obj_D.C::id_A = 100; specify which path we are going

    // After adding virtual 
    obj_D.id_A = 10;

    obj_D.id_B = 20;
    obj_D.id_C = 30;
    obj_D.id_D = 40;

    cout << "\n A from ClassB  : " << obj_D.B::id_A;
    cout << "\n A from ClassC  : " << obj_D.C::id_A;
 
    cout << "\n B : " << obj_D.id_B;
    cout << "\n C : " << obj_D.id_C;
    cout << "\n D : " << obj_D.id_D << endl; 
}