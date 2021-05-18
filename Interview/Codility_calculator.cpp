#include <iostream>
#include <vector>
#include <string>
#include <math.h> 
using namespace std;
int isCh(char);
bool addFunc(vector<double>&);
bool minusFunc(vector<double>&);
bool multiFunc(vector<double>&);
bool divFunc(vector<double>&);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // vector<char> input;
    string input;
    getline(cin,input);
    // cout << input << endl;
    vector<double> numbers;
    bool errorFlag = 0;
    bool operatorExist = 0;
    for(int i = 0; i < input.size();i++){
        if(isCh(input[i]) > 0){
            operatorExist = 1;
            switch (isCh(input[i])) {
                case 1:
                    errorFlag = addFunc(numbers);
                    break;
                case 2:
                    errorFlag = minusFunc(numbers);
                    break;
                case 3:
                    errorFlag = multiFunc(numbers);
                    break;
                case 4:
                    errorFlag = divFunc(numbers);
                    break;
                default:
                    cout << "Error" << endl;
            }
        }
        else if(input[i] >= 48 && input[i] <= 57 ){
            // input of number start
            string numIntStr = "";
            string numDobStr = "";
            bool doubleStart = 0;
            while(input[i] != ' ' && input[i] != '\0'){
                if(input[i] == '.' && doubleStart == false){
                    doubleStart = true;
                }
                else if(input[i] == '.' && doubleStart == true){
                    cout << "Invalid operand" << endl;
                    return 0;
                }
                else if(doubleStart == false){
                    numIntStr += input[i] - 48;
                }else if(doubleStart == true){
                    numDobStr += input[i] - 48;
                }
                i++;
            }
            double numDo = 0;
            // cout << "Debug Start" << endl;
            for(int i = numIntStr.size() - 1; i >=  0; i--){
                // cout << pow(10,numIntStr.size() - 1 - i) << endl;
                // cout << numIntStr[i]*pow(10,numIntStr.size() - 1 - i) << endl;
                numDo += numIntStr[i]*pow(10,numIntStr.size() - 1 - i);
            }
            // cout << "Debug: " << numDobStr << endl;
            for(int i = 0;  i < numDobStr.size(); i++){
                // cout << pow(0.1,i) << endl;
                // cout << numDobStr[i]*pow(0.1,i) << endl;
                numDo += numDobStr[i]*pow(0.1,i+1);
            }
            numbers.push_back(numDo);
        }else if(input[i] == ' '){
            // ignore
        }
        else{
            // should ignore
            cout << "Invalid operator" << endl;
            errorFlag = 1;
            return 0;
        }
        if(errorFlag == true){
            break;
        }
    }
    // cout << numbers.size() << endl;
    // if(operatorExist == 0){
    //     cout << "Too many operands" << endl;
    //     return 0;
    // }
    if(numbers.size() > 1){
        cout << "Too many operands" << endl;
    }
    else if(errorFlag == false) {
        cout << numbers.back() << endl;
    }
    return 0;
}
int isCh(char ch){
    if(ch == '+'){
        return 1;
    }else if(ch == '-'){
        return 2;
    }else if(ch == '*'){
        return 3;
    }else if(ch == '/'){
        return 4;
    }else return 0;
}
bool addFunc(vector<double>& numbers){
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double a = numbers.back();
    numbers.pop_back();
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double b = numbers.back();
    numbers.pop_back();
    numbers.push_back(b+a);
    return 0;    
}
bool minusFunc(vector<double>& numbers){
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double a = numbers.back();
    numbers.pop_back();
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double b = numbers.back();
    numbers.pop_back();
    // cout << b << " " << a << endl;
    numbers.push_back(b-a);
    return 0;
}
bool multiFunc(vector<double>& numbers){
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double a = numbers.back();
    numbers.pop_back();
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double b = numbers.back();
    numbers.pop_back();
    numbers.push_back(b*a);
    return 0;   
}
bool divFunc(vector<double>& numbers){
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double a = numbers.back();
    numbers.pop_back();
    if(numbers.size() == 0){
        cout << "Not enough operands" << endl;
        return 1;
    }
    double b = numbers.back();
    numbers.pop_back();
    numbers.push_back(b/a); 
    return 0;   
}