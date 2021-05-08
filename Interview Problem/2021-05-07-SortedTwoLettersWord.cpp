// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    const char A = 'A';
    int numB = 0;
    int minDels = 0;

    for(int i = 0; i < S.size(); i++){
        if(A == S[i]){
            minDels = min(numB, minDels + 1);
        }
        else{
            numB++;
        }
    }
    return minDels;
}
