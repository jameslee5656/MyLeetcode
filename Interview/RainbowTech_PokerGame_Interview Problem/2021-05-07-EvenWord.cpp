// you can use includes, for example:
#include <algorithm>
#include <unordered_map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<char,int> umap;
    for(int i = 0; i < S.size(); i++){
        umap[S[i]]++;
    }
    int count = 0;
    for (auto const &pair: umap) {
        // std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        if(pair.second % 2 == 1){
            count++;
        }
    }
    return count;
}
