/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> element;
        DFS(root,element);
        return ans;
    }
    void DFS(TreeNode* root,vector<int> element){
        if(root->left == nullptr && root->right == nullptr){
            string str;
            for(int i = 0; i < element.size(); i++){
                str += to_string(element[i]);
                str += "->";
            }
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }
        element.push_back(root->val);
        if(root->left != nullptr) DFS(root->left,element);
        if(root->right != nullptr) DFS(root->right,element);
        element.pop_back();
    }
};
// @lc code=end

