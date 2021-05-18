// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    for(int i = 0; i < S.size() - 1; i++){
        if(S[i] == S[i+1]){
            if(C[i] < C[i+1]){
                ans+=C[i];
            }else{
                ans+=C[i+1];
            }
        }
    }
    return ans;
}
