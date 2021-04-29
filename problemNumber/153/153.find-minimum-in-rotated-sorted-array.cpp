/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1, 5001);
    }
    int dfs(vector<int>& nums, int i, int j, int min){
        if(i == j){
            if(nums[i] < min) min = nums[i];
            return min;
        };
        int mid = (i+j)/2;
        int leftMin = dfs(nums,i,mid,min);
        if(leftMin < min) min = leftMin;
        int rightMin = dfs(nums,mid+1,j,min);
        if(rightMin < min) min = rightMin;
        return min;
    }
};
// @lc code=end

