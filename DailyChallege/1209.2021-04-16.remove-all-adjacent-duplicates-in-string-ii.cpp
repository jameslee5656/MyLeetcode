/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<string> delList;
        pair<char,int> recPair(s[0],1);
        int cur = 1;
        while(cur != s.size()){
            // cout << cur << ". " << s[cur] << endl;
            if(s[cur-1] == s[cur]) recPair.second++;
            else{
                recPair.first = s[cur];
                recPair.second = 1;
            }
            if(recPair.second == k){
                // cout << s << endl;
                // cout << s[cur-k+1] << " " << cur-k+1 << endl;
                // cout << s[cur] << " " << cur << endl;
                s.erase(s.begin()+cur-k+1, s.begin()+cur+1);
                cur = 0;
                recPair.first = s[cur];
                recPair.second = 1;
                // cout << s << endl;
            }
            cur++;
        }
        return s;
    }
};     
// @lc code=end

