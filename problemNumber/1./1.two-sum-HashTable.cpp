/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tmap;
        vector<int> ans;
        for(int i = 0; i < nums.size();i++){
            // cout << num << endl;
            if(tmap.find(target - nums[i])!=tmap.end()){
                ans.push_back(tmap[target - nums[i]]);
                ans.push_back(i);
            }else{
                tmap[nums[i]] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

