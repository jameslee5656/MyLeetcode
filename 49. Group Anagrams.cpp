class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<int>> strsIntVec;
        strsIntVec.resize(strs.size());
        vector<int> temptVec;
        int tempt;
        
        for(int a=0; a < strs.size(); a++){
            temptVec.clear();
            for(int b=0; b < strs[a].size(); b++){
                temptVec.push_back(strs[a][b] - 97);
            }
            sort(temptVec.begin(),temptVec.begin()+temptVec.size());
            strsIntVec[a] = temptVec;
        }
        
        for(int a=0; a < strsIntVec.size(); a++){
            for(int b=0; b < strsIntVec[a].size(); b++){
                cout << strsIntVec[a][b] << ", ";
            }
            cout << endl;
        }
        
        vector<vector<string>> ret; // x[M][N]
        // ret.resize(3);
        // for(int i=0; i!=3; ++i) ret[i].resize(3);
        
        int M=0;
        while (strs.size() != 0){
            temptVec.clear();
            ret.push_back(vector<string>());
            ret[M].push_back(strs[0]);
            for (int a=1; a < strs.size(); a++){
                if (strsIntVec[0]==strsIntVec[a]){
                    ret[M].push_back(strs[a]);
                    temptVec.push_back(a);
                }
            }
            
            for(int a=temptVec.size()-1; a>=0; a--){
                strs.erase(strs.begin() + temptVec[a]);
                strsIntVec.erase(strsIntVec.begin() + temptVec[a]);
            }
            strs.erase(strs.begin());
            strsIntVec.erase(strsIntVec.begin());
            for(int a=0; a < strs.size(); a++){
                cout << strs[a] << ", ";
            }
            cout << "strs.size(): " << strs.size() << endl;
            M++;
        }
        
        cout << endl;
        
        for(int a=0; a < strsIntVec.size(); a++){
            for(int b=0; b < strsIntVec[a].size(); b++){
                cout << strsIntVec[a][b] << ", ";
            }
            cout << endl;
        }
        return ret;
    }
};