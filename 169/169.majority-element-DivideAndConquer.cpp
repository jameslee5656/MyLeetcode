/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n-1).first; // the number count > n/2, second divide and conquer extra
    }
    pair<int,int> dfs(vector<int>& nums, int i, int j){
        if(i==j) {
            pair<int,int> newv(nums[i],1);
            return newv;
        }
        int mid = (i+j) / 2;
        pair<int,int> left = dfs(nums, i, mid);
        pair<int,int> right = dfs(nums, mid+1, j);
        if (left.first == right.first){
            pair<int,int> newv(left.first,left.second+right.second);
            return newv;
        }
        else {
            if(left.second >= right.second){
                pair<int,int> newv(left.first,left.second-right.second);
                return newv;
            } 
            else{
                pair<int,int> newv(right.first,right.second-left.second);
                return newv;
            } 
        } 
    }
};

// @lc code=end

