/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 * 這一篇我想要利用有幾個英文數字來加速但並有很有效的解決問題
 * 翻找資料最好的方式是用 map 來解決 -> start with v2
 * 
 * Case 114 沒過，繼續減少time
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
        
        unordered_map<string, string> umap;
        for(int a=0; a < strs.size(); a++){
            // character - a's ASCII number 97 = 0~26
            sort(strsOrdered[a].begin(),strsOrdered[a].end());
            umap[strs[a]] = strsOrdered[a];
        }
        vector<string>::iterator it= strs.begin();
        int num = -1;
        while(strs.size()!=0){
            if(it == strs.begin() && (next(it) == strs.end())){
                ret.push_back(vector<string>());
                num++;
                ret[num].push_back(strs.front());
                strs.erase(strs.begin());
                break;
            }
            else if(it == strs.begin()){
                ret.push_back(vector<string>());
                num++;
                strtempt = umap[*it];
                advance(it,1);
            }
            else if ((next(it,1) == strs.end()) && (umap[*it] == strtempt)){
                // Need to push back the end
                ret[num].push_back(*it);
                strs.erase(it);

                ret[num].push_back(strs.front());
                strs.erase(strs.begin());
                it = strs.begin();
            }
            else if (umap[*it] == strtempt){
                ret[num].push_back(*it);
                strs.erase(it);
            }
            else if(next(it,1) == strs.end()){
                ret[num].push_back(strs.front());
                strs.erase(strs.begin());
                it = strs.begin();
            }
            else if(umap[*it] != strtempt){
                advance(it,1);
            }
        }
        return ret;
    }
};
// @lc code=end

