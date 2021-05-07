#include <iostream>
using namespace std;
int main(){
    int x = 5;
    char y = 't';

    const int* i = &x;
    const char* j = &y;

    cout << *i << " " << *j << endl;

    // The pointed variable can be changed;
    x = 7;
    y = 'k';
    cout << *i << " " << *j << endl;
    
    int a = 7;
    char b = 'k';
    i = &a;
    j = &b;


    // error: read-only variable is not assignable
    // *i = 7;
    // ~~ ^
    //  error: read-only variable is not assignable
    // *j = 'k';
    // ~~ ^
    cout << *i << " " << *j << endl;

    // #####################-------------------#####################
    // data_type* const var_name
    // x and z non-const var
    int x1 = 5;
    int z1 = 6;
 
    // y and p non-const var
    char y1 = 'A';
    char p1 = 'C';
 
    // const pointer(i) pointing
    // to the var x's location
    int* const i1 = &x;
 
    // const pointer(j) pointing
    // to the var y's location
    char* const j1 = &y;
 
 
    // The values that is stored at the memory location can modified
    // even if we modify it through the pointer itself
    // No CTE error
    *i1 = 10;
    *j1 = 'D';
 
    // CTE because pointer variable
    // is const type so the address
    // pointed by the pointer variables
    // can't be changed
    // *i = &z;
    // *j = &p;
 
    cout << *i1 << " and " << *j1 << endl;
    cout << i1 << " and " << j1;
}