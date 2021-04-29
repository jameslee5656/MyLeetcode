/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 * 這一篇我想要利用有幾個英文數字來加速但並有很有效的解決問題
 * 翻找資料最好的方式是用 map 來解決
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // strsIntVec is for storing information for each element
        vector<vector<int>> strsIntVec;
        //strsIntVec.resize(strs.size());
        vector<int> temptVec;
        int tempt;
        int* ptempt;
        // Return vector
        vector<vector<string>> ret; // x[M][N]
        // First order up the alphabet numbers in each strs element
        temptVec.push_back(strs[0].size());
        ret.push_back(vector<string>());
        vector<int>::iterator result;
        for(int a=1; a< strs.size(); a++){
            result = find(temptVec.begin(), temptVec.end(), strs[a].size());
            if (result !=  temptVec.end()){
                // cout << "It did find it" << endl;
                // cout << distance(temptVec.begin(),result) << endl;
                // cout << strs[a] << endl;
                ret[distance(temptVec.begin(),result)].push_back(strs[a]);
            }
            else{
                // cout << "Did not find it" << endl;
                temptVec.push_back(strs[a].size());
                ret.push_back(vector<string>());
                ret[ret.size()-1].push_back(strs[a]);
            }
        }
        for(int a=0; a < ret.size(); a++){
            for(int b=0; b < ret[a].size(); b++){
                cout << ret[a][b] << ", ";
            }
            cout << endl;
        }

        for(int a=0; a < ret.size(); a++){
            for(int b=0; b < ret[a].size(); b++){
                temptVec.clear();
                // character - a's ASCII number 97 = 0~26
                for(int c=0; c < ret[a][b].size(); c++){
                    temptVec.push_back(ret[a][b][c] - 97);
                }
                sort(temptVec.begin(),temptVec.begin()+temptVec.size());
                strsIntVec.push_back(temptVec);
            }
        }

        for(int a=0; a < strsIntVec.size(); a++){
            for(int b=0; b < strsIntVec[a].size(); b++){
                cout << strsIntVec[a][b] << ", ";
            }
            cout << endl;
        }

    //     int M=0; // Row number
    //     while (strs.size() != 0){
    //         temptVec.clear();
    //         ret.push_back(vector<string>());
    //         ret[M].push_back(strs[0]);
    //         for (int a=0; a < strs.size(); a++){
    //             if (strsIntVec[0]==strsIntVec[a]){
    //                 ret[M].push_back(strs[a]);
    //                 temptVec.push_back(a);
    //             }
    //         }
            
    //         for(int a=temptVec.size()-1; a>=0; a--){
    //             strs.erase(strs.begin() + temptVec[a]);
    //             strsIntVec.erase(strsIntVec.begin() + temptVec[a]);
    //         }
    //         strs.erase(strs.begin());
    //         strsIntVec.erase(strsIntVec.begin());
    //         for(int a=0; a < strs.size(); a++){
    //             cout << strs[a] << ", ";
    //         }
    //         cout << "strs.size(): " << strs.size() << endl;
    //         M++;
    //     }
        
    //     cout << endl;
        
    //     for(int a=0; a < strsIntVec.size(); a++){
    //         for(int b=0; b < strsIntVec[a].size(); b++){
    //             cout << strsIntVec[a][b] << ", ";
    //         }
    //         cout << endl;
    //     }
        cout << "Debut ret2 vector" << endl;  
        vector<vector<string>> ret2; // x[M][N]
        int co_strsIntVec = 0; // count where the strsIntVec is going
        int co_begin = 0;
        int co_cmp = 0;
        for(int a=0; a < 1; a++){
            // 重新分組，一樣的分到新的，直到依樣
            // Same as the back assemble into new vector
            ret2.push_back(vector<string>());
            ret2.back().push_back(ret[a].front());
            ret[a].erase(ret[a].begin());
            co_begin = co_strsIntVec;
            co_cmp = co_strsIntVec;
            co_next = -1;
            while(ret[a].size() != 0){
                if(strsIntVec[co_begin]==strsIntVec[co_cmp]){
                    ret2.back().push_back(ret[a].front());
                    ret[a].erase(ret[a].begin());
                    co_cmp++;
                }
                else if ((co_next == -1) && (strsIntVec[co_begin]!=strsIntVec[co_cmp])){
                    co_next = co_cmp;
                    ret2.back().push_back(ret[a].front());
                    ret[a].erase(ret[a].begin());
                    co_cmp++;
                }
                else if ((co_next != -1) && (strsIntVec[co_begin]!=strsIntVec[co_cmp])){
                    ret2.back().push_back(ret[a].front());
                    ret[a].erase(ret[a].begin());
                    co_cmp++;
                }
                else if(ret[a][co_cmp] == )// I need to know if it is the last element
                // else{
                //     ret2.back().push_back(ret[a].front());
                //     ret[a].erase(ret[a].begin());
                //     co_strsIntVec = co_begin;
                // }
                cout << ret2[0].back() << endl;
            //}
            

            // cout << ret2[0] << endl;
        }
    return ret;
    }
};
// @lc code=end

