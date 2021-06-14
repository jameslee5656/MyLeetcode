#include <iostream>
using namespace std;
void DFS(int& num, int n){
    if(n==1) return;
    num*= n;
    DFS(num,n-1);
}
int main(){
    int n = 5;
    int product = 1;
    for(int i = n; i > 0; i--){
        product *= i;
        cout << i << endl;
    }
    cout << product << endl;

    int product2 = 1;
    DFS(product2, n);
    cout << product2 << endl;

}