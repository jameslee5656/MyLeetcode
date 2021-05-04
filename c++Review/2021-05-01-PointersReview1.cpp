#include <iostream>
using namespace std;
int main(){
    int a = 5;
    int* p = &a;
    cout << p << endl; //0x7ffee848257c c->d->e->f->0 hex per move is one byte
    cout << "size of integer is " << sizeof(int) << " bytes" << endl;
    cout << p + 1 << endl; //0x7ffee8482580
    // 
}