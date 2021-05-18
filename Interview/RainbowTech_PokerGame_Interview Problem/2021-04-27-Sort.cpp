#include <vector>
#include <string>
#include <iostream>
using namespace std;
// Swap function
void swap(vector<int>& input,int i,int j){
    int tempt = input[i];
    input[i] = input[j];
    input[j] = tempt;
}
// Partition function
int partition(vector<int>& input,int front,int back){
    int i = front - 1;
    int piv = input[back];
    for(int j = front; j < back; j++){
        if(piv > input[j]){
            i++;
            swap(input, i, j);
        }
    }
    i++;
    swap(input, i, back);
    return i;
}
// QuickSort function
void quickSort(vector<int>& input, int front, int back){
    if(front<back){
        int m = partition(input, front, back);
        quickSort(input, front, m-1);
        quickSort(input, m+1, back);
    }
}
std::string f(const std::vector<int>& input)
{      
    // Due to const, copy a input
    vector<int> inputCopy = input;
    quickSort(inputCopy, 0, inputCopy.size() -1);
    // Concatenate the string
    string ans;
    for(int i = 0; i < inputCopy.size() - 1; i++){
        ans+= to_string(inputCopy[i]);
        ans+= " ";
    }
    ans+= to_string(inputCopy[inputCopy.size()-1]);
    return ans;
}
int main(){
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(5);

    cout << f(nums) << endl;
}
