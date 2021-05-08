/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 * 
 * Answer https://molchevskyi.medium.com/best-solutions-for-microsoft-interview-tasks-min-deletions-to-obtain-string-in-right-format-37a3365ce348
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int minDel = 0;
        int Bnum = 0;
        for(auto c: s){
            if(c == 'a'){
                minDel = min(minDel + 1, Bnum);
            }else{
                Bnum++;
            }
        }
        return minDel;
    }
};
// @lc code=end

