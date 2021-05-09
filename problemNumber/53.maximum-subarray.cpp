/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    map<int,int> omap;
    int maxSubArray(vector<int>& nums) {
        int maxPos = 0;
        int maxSum = nums[0];
        omap[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(maxSum + nums[i] <= nums[i]){
                maxSum = nums[i];
            }
            else maxSum += nums[i];
            // cout << "i: " << i << " maxSum: " << maxSum << endl;
            omap[i] = maxSum;
            if (omap[i] > omap[maxPos]) maxPos = i;
        }
        return omap[maxPos];
        // if (maxPos == minPos){ return omap[maxPos];}
        // else if (omap[minPos] < 0 && minPos < maxPos) return omap[maxPos] - omap[minPos];
        // else if (omap[minPos] > 0) {return omap[maxPos];}
        // else {return omap[maxPos]; cout << "Debug" << endl;}
    }
};
// @lc code=end

