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
void splitword2(string s){

    string delimiter = ">=";
    string token; // = s.substr(0, s.find(delimiter)); // token is "scott"
    int pos = 0;
    while((pos = s.find(delimiter)) != string::npos){
        token = s.substr(0, pos);
        cout << token << endl;
        s.erase(0, pos + delimiter.length());
    }
    cout << s << endl;
}

int main(){
    string s = "geeks for geeks geeks "
               "contribution placements";
    int num = countWords(s,' ');
    cout << " Number of words are: " << num << endl;
    s = "a,b,c,def";
    num = countWords(s,',');
    cout << " Number of words are: " << num << endl;
    // return 0;

    // Using string split
    s = "scott>=tiger";
    splitword2(s);
    s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";
    splitword2(s);
}