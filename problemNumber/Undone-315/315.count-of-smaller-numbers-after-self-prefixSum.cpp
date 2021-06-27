/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    struct bst_n{
        bst_n *r = nullptr;
        bst_n *l = nullptr;
        int value = 0;
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> sorted_vec = nums;
        sort(sorted_vec.begin(), sorted_vec.end());
        unordered_map<int,int> umap_rank;
        int r = 0;
        sorted_vec[0] = r++;
        for(int i = 1; i < sorted_vec.size(); i++){
            if(sorted_vec[i] != sorted_vec[i - 1]){
                umap_rank[sorted_vec[i]] = r++;
            }
            else umap_rank[sorted_vec[i]] = r;
        }
        ans.push_back(0);
        int prefixSum = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            
        }
        return ans;
    }
};
// @lc code=end

