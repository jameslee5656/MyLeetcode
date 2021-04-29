/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 * 這一篇我想要利用有幾個英文數字來加速但並有很有效的解決問題
 * 翻找資料最好的方式是用 map 來解決 -> start with v2
 * 
 * Case 114 沒過，繼續減少time
 * 
 * 技巧：不要先建立Hash Map，而是一邊建立一邊檢查是否為新詞
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //strsIntVec.resize(strs.size());
        vector<int> temptVec;
        int tempt;
        int* ptempt;
        string strtempt;
        // Return vector
        vector<vector<string>> ret; // x[M][N]
        // Establish a hashed map for the cooresponding key;
        vector<string> strsOrdered;
        strsOrdered = strs; // Also copy one for sorting
        
        unordered_map<string, int> umap;
        // for(int a=0; a < strs.size(); a++){
        //     if()
        // }


        for(int a=0; a < strs.size(); a++){
            // character - a's ASCII number 97 = 0~26
            strtempt = strs[a];
            sort(strtempt.begin(),strtempt.end());
            if (umap.count(strtempt) == 0){
                umap[strtempt] = ret.size();
                ret.push_back({});
            }
            ret[umap[strtempt]].push_back(strs[a]);
            // cout << strsOrdered[a] << "  " << umap.count(strsOrdered[a]) << endl;
            // }
            // umap[strs[a]] = strsOrdered[a];
        }

        return ret;
    }
};
// @lc code=end

