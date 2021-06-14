#include <iostream>
#include <string>
#include <vector>
#include <math.h> 
using namespace std;

int stringToInt(string str){
    if(str.size()>10){
        cout << "Over the int size" << endl;
        return 0;
    }
    bool negflag = 0;
    int ans = 0;
    vector<int> vec;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '-'){
            negflag = 1;
        }
        else{
            if(negflag == 0){
                ans += (str[i] - 48) * pow(10,(str.size() - i - 1));
            }
            else if(i != 0){
                ans += (str[i] - 48) * pow(10,(str.size() - i - 1));
                // cout << pow(10,(str.size() - i - 1)) << endl;
            }
        }
    }
    if(negflag == 1){
        ans *= -1;
    }
    cout << ans << endl;
    return ans;
}
int main(){
    // string str = "100";
    // stringToInt(str);
    string str2 = "-100";
    stringToInt(str2);
}