/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        // If this is empty then results then the for loop below won't run
        vector<string> results{""}; 
        vector<string> phones{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(char digit: digits){
            vector<string> tmp;
            for(string result: results){
                for(char phone: phones[digit - '0' - 2]){
                    tmp.push_back(result + phone);
                }
            }
            results.swap(tmp);
        }
        
        return results;
    }
    
};
// @lc code=end

