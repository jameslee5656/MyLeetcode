/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int curSum = 0;
        int count = 0;
        for(auto m : nums){
            curSum += m;
            if(curSum == k) count++;
            if(umap.count(curSum-k)!=0)count += umap[curSum-k];
            if(umap.count(curSum)==0) umap[curSum] = 1;
            else umap[curSum]++;
        }
        return count;
    }
};
// @lc code=end
// [3,4,7,2,-3,1,4,2]\n7
