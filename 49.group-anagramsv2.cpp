/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 * 這一篇我想要利用有幾個英文數字來加速但並有很有效的解決問題
 * 翻找資料最好的方式是用 map 來解決 -> start with v2
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // strsIntVec is for storing information for each element
        vector<string> strsIntVec;
        //strsIntVec.resize(strs.size());
        vector<int> temptVec;
        int tempt;
        int* ptempt;
        string strtempt;
        // Return vector
        vector<vector<string>> ret; // x[M][N]
        // Establish a hashed map for the cooresponding key;
        strsOrdered = strs; // Also copy one for sorting
        
        unordered_map<string, string> umap;
        for(int a=0; a < strs.size(); a++){
            // character - a's ASCII number 97 = 0~26
            sort(strsOrdered[a].begin(),strsOrdered[a].end());
            umap[strs[a]] = strsOrdered[a];
            cout << umap[strs[a]] << endl;
        }
        vector<string>::iterator it= strs.begin();
        while(strs.size()!=0){
            if(*it == strs.begin()){
                ret.push_back(vector<string>());
                ret.back().push_back(*it);
            }
        }
      
    return ret;
    }
};
// @lc code=end

