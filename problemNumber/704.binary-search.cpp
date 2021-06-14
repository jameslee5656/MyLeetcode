/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int num = DFS_find(nums, target, 0, nums.size() - 1);
        return num;
    }
    int DFS_find(vector<int>& nums, int target, int start, int end){
        cout << "Debug: " << start << " " << end << endl;
        if(start >= end){
            if(nums[start] == target) return start;
            else return -1;
        }
        int n =  start + (end + 1 - start) / 2;
        if(target == nums[n]){
            return n;
        }
        else if (target > nums[n]){
            return DFS_find(nums, target, n, end);
        }
        else if(target < nums[n]){
            return DFS_find(nums, target, start, n - 1);
        }
        return -1;
    }
};
// @lc code=end

