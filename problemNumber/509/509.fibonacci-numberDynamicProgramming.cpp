/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    unordered_map<int,int> umap;
    int fib(int n) {
        if(n == 0) return 0;
        if (n == 1) return 1;
        if(umap.find(n) != umap.end()){
            return umap[n];
        }
        umap[n] = fib(n-1) + fib(n-2);
        return umap[n];
    }
};

// @lc code=end
// @lc code=end

