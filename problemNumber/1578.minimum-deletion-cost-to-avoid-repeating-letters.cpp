/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Deletion Cost to Avoid Repeating Letters
 */

// @lc code=start
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i+1]){
            if(cost[i] < cost[i+1]){
                ans+=cost[i];
            }else{
                ans+=cost[i+1];
                cost[i+1] = cost[i];
            }
        }
    }
    return ans;
    }
};
// @lc code=end

