#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int countWords(string str,char token){
    // breaking input into word using string stream
    stringstream s(str); // Used for breaking words;
    string word;
    // string token;
    int count = 0;
    while(getline(s,word,token)){
        cout << word << endl;
        count++;
    }
    return count;
}
int main(){
    string s = "geeks for geeks geeks "
               "contribution placements";
    int num = countWords(s,' ');
    cout << " Number of words are: " << num << endl;
    s = "a,b,c,def";
    num = countWords(s,',');
    cout << " Number of words are: " << num << endl;
    return 0;
}