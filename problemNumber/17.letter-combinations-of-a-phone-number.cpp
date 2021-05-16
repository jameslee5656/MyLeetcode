/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    string path;
    int n;
    vector<string> phone{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void DFS(string digits){
        if(path.size() == digits.size()){
            if(path!="") result.push_back(path);
            path.pop_back();
            n -= 1;
            return;
        }
        // string to int (ASKII - 48) + 2 (start with 2)
        int k = digits[n] - 48 - 2;
        // cout << k << endl;
        for(int i = 0; i < phone[k].size(); i++){
            // cout << phone[k][i] << endl;
            path+=phone[k][i];
            // cout << path << endl;
            n+=1;
            // cout << "n: " << n << endl;
            DFS(digits);
        }
        path.pop_back();
        n-=1;
        // cout << "Debug path pop: " <<path << endl;


    }
    vector<string> letterCombinations(string digits) {
        
        // vector<string> ans;
        
        // int num;
        // for(int i = 0; i < digits.size(); i++){
        //     num = digits[i] - 50;
        //     cout <<  num << endl;
        // }
        DFS(digits);
        return result;
    }
    
};
// @lc code=end

