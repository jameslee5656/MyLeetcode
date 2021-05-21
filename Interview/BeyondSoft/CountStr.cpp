#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void count_1 (string str){
    unordered_map<string,int> umap;
    string cut = " ";
    int pos =0;
    string word = "";
    cout << str << endl;
    while((pos = str.find(cut)) != string::npos){
        word = str.substr(0, pos);
        // cout << word << endl;
        // cout << word << " " << (umap.find(word) != umap.end()) << endl;
        if (umap.find(word) == umap.end()){
            umap[word] = 1;
        }else umap[word]++;
        str.erase(0, pos + cut.length());
    }
    word = str.substr(0, pos);
    if (umap.find(word) == umap.end()){
            umap[word] = 1;
        }else umap[word]++;
    for(auto &pair: umap){
        cout << pair.first << " " << pair.second << endl;
    }
}
int main(){
    string ex1 = "this is this is this abc";
    count_1(ex1);
}