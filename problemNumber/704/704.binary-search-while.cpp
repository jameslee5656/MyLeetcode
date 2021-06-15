/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int n = 0;
        while(left < right){
            n = left + (right - left) / 2;
            if (nums[n] == target) return n;
            else if(nums[n] > target){
                right = n;
            }
            else{
                left = n + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

