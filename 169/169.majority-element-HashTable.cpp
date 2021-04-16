/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        pair<int,int> CurrentMax (0,-1); // first number second count
        while(!nums.empty()){
            if(umap.count(nums.back())==0){
                umap[nums.back()] = 0;
            }
            umap[nums.back()]++;
            if(CurrentMax.second < umap[nums.back()]){
                CurrentMax.second = umap[nums.back()];
                CurrentMax.first = nums.back();
            }
            nums.pop_back();
        }
        return CurrentMax.first;

    }
};
// @lc code=end

