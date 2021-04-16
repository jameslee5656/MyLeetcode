/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    int dfs(vector<int>& nums, int i, int j){
        if(i == j) return nums[i];
        int mid = (i+j)/2;
        if(nums[i]<nums[j]) return nums[i];
        else {
            int leftMin = dfs(nums,i,mid);
            int rightMin = dfs(nums,mid+1,j);
            if(leftMin < rightMin) return leftMin;
            else return rightMin;
        }
    }
};
// @lc code=end

