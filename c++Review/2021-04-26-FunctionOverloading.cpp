#include <iostream>
using namespace std;
int square(int, int);
float square(float, float);


int main(){
    int integer = square(5,6);
    float floatNumber = square(0.11f,0.11f);
    cout << integer << endl;
    cout << floatNumber << endl;
}

int square(int x, int y){
    return x * y;
}
float square(float x, float y){
    return x * y;
}

// int plusFunc(int x, int y) {
//   return x + y;
// }

// double plusFunc(double x, double y) {
//   return x + y;
// }

// int main() {
//   int myNum1 = plusFunc(8, 5);
//   double myNum2 = plusFunc(4.3, 6.26);
//   cout << "Int: " << myNum1 << "\n";
//   cout << "Double: " << myNum2;
//   return 0;
// }