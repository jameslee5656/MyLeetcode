/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    unordered_map<int,int> umap;
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if (n == 2) return 2;
        if(umap.find(n) == umap.end()){
            umap[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return umap[n];
    }
};
// @lc code=end

