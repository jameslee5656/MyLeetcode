#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int i, int j){
    int tempt = nums[i];
    nums[i] = nums[j];
    nums[j] = tempt;
}
int partition(vector<int> &nums, int front, int end){
    int pivot = nums[end];
    // cout << "Debug pivot: "<< pivot<< endl;
    int i = front - 1;
    // cout << pivot << " " << i << endl;
    for (int j  = front; j < end; j++){
        // cout << "Debug j: "<<j << endl;
        if(nums[j] < pivot){
            i++;
            swap(nums, i, j);
            // cout << "Debug i: "<<i << endl;

        }
    }
    i++;
    swap(nums, i, end);
    // for(int i = 0; i < 10; i++){
    //     cout << nums[i] << endl;
    // }
    return i;
}
void quicksort(vector<int> &nums, int i, int j){
    if(i < j){
        int m = partition(nums, i, j);
        // cout << "Debug: m "  << m << endl;
        // return;
        quicksort(nums, i, m-1);
        quicksort(nums, m+1, j);
    }
}
int main(){
    vector<int> nums;
    srand (time(NULL));
    for(int i = 0; i < 10; i++){
        int b = rand() % 50;
        nums.push_back(b);
    }
    // nums.push_back(9);
    // nums.push_back(4);
    // nums.push_back(1);
    // nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(3);
    // nums.push_back(8);
    // nums.push_back(2);
    // nums.push_back(5);

    quicksort(nums, 0, nums.size() -1);
    for(int i = 0; i < 9; i++){
        cout << nums[i] << endl;
    }
}


