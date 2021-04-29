#include <iostream>
using namespace std;

class myClass{
    public:
        int val1;
        myClass(int x){
            cout << "Myclass Constructor called" << endl;
            val1 = x;
        }
};
class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}
int main(){
    myClass myObject(45);
    cout << "myObject.val1 default value: " << myObject.val1 << endl;
    Car carObj2("Ford", "Mustang", 1969);
}