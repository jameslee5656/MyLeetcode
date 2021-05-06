/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // cout << s << endl;
        vector<char> vec;
        for(string::iterator it = s.begin(); it < s.end(); it++){
            if(*it >= 65 && *it <= 90){
                vec.push_back(*it + 32);
            }
            else if(*it >= 97  && *it <= 122){
                vec.push_back(*it);
            }
            // it seems that number is considered
            else if(*it >= 48  && *it <= 57){ 
                vec.push_back(*it);
            }
        }
        for(int i = 0; i < vec.size()/2; i++){
            cout << i << " " << vec.size() - i -1 << endl;
            if(vec[i] != vec[vec.size() - i -1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

