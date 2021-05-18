/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    // A map tell the duplicate file location of ans
    unordered_map<string,int> umapNum;
    unordered_map<string,string> umapAns0;
    unordered_map<string,int> umapPos;
    vector<vector<string>> ans;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(auto pathContent : paths){
            // split the space
            std::istringstream iss(pathContent); 
            std::vector<std::string> eachPath{ 
                std::istream_iterator<std::string>(iss), {} 
            }; 
            // cout << result.size() << endl;
            string filePath = eachPath[0];
            for(int i = 1; i < eachPath.size(); i++){
                char splitNote = '(';
                string fileName = eachPath[i].substr(0,eachPath[i].find(splitNote));
                string content = eachPath[i].substr(eachPath[i].find(splitNote),eachPath[i].size());
                // cout << fileName << " " << content << endl;
                if(umapNum.find(content)!=umapNum.end() && umapNum[content] > 1){
                    ans[umapPos[content]].push_back(filePath+'/'+fileName);
                    umapNum[content]++;
                }
                else if(umapNum.find(content)!=umapNum.end() && umapNum[content] == 1){
                    umapNum[content]++;
                    umapPos[content] = ans.size();
                    ans.push_back({umapAns0[content]});
                    ans[umapPos[content]].push_back(filePath+'/'+fileName);
                }
                else if(umapNum.find(content)==umapNum.end()){
                        umapNum[content] = 1;
                        umapAns0[content] = filePath+'/'+fileName;
                }
                else{
                    cout << "Debug Error" << endl;
                }
            }
        }
        // for(vector<vector<string>>::iterator it = ans.begin();it!=ans.end();){
        //     if((*it).size() == 1) it = ans.erase(it);
        //     else ++it;
        // }
        //  for (auto const &pair: umapNum) {
        //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        // }
        //  for (auto const &pair: umapAns0) {
        //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        // }
        //  for (auto const &pair: umapPos) {
        //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        // }
        return ans;
    }
};
// @lc code=end

