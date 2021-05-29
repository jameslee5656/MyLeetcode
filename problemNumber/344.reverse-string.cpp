/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // vector<char>& s_r;
        char tempt;
        for(int i = 0; i < s.size() / 2; i++){
            // tempt = s[i];
            // s[i] = s[s.size() -1 - i];
            // s[s.size() -1 - i] = tempt;
            // In place Swap
            //(a = A + B)
            s[i] += s[s.size() -1 - i];
            //(b = A + B - B = A)
            s[s.size() -1 - i] =  s[i] - s[s.size() -1 - i];  
            //(a = A + B - A = B)  
            s[i] = s[i] - s[s.size() -1 - i];
        }
    }
};
// @lc code=end

