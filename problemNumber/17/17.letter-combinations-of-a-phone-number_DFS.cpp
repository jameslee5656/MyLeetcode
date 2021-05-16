/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<string>& result, vector<string> const phone,
            string& path,string digits, int& layer){
        if(path.size() == digits.size()){
            if(path!="") result.push_back(path);
            path.pop_back();
            layer -= 1;
            return;
        }
        // string to int (ASKII - 48) + 2 (start with 2)
        // phone number which one will be digit number accordingly
        // k will be the phone number that we need to iterate
        int k = digits[layer] - 48 - 2;
        for(int i = 0; i < phone[k].size(); i++){
            path+=phone[k][i];
            layer+=1;
            DFS(result, phone, path, digits, layer);
        }
        path.pop_back();
        layer-=1;

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path;
        // which layer I am
        // Need to be global -> so that n could be delete
        int layer = 0; 
        vector<string> phone{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        DFS(result, phone, path, digits, layer);
        return result;
    }
    
};
// @lc code=end

