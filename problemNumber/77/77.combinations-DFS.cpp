/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> num;
        for(int i = 1; i <= n ; i++){
            num.push_back(i);
            DFS(i,n,1,k,num,ans);
            num.pop_back();
        }
        return ans;
    }
    void DFS(int i ,int n,int layer, int k, vector<int> num,vector<vector<int>>& ans){
        if(layer == k){
            ans.push_back(num);
            return;
        }
        if(i == n) return ;
        for(int j = i + 1; j <= n; j++){
            num.push_back(j);
            DFS(j,n,layer+1,k,num,ans);
            num.pop_back();
        }
        return;
    }
};
// @lc code=end

