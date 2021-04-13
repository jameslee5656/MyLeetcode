/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        vector<int> result;
        while(!stk.empty()||root!=nullptr){
            while(root != nullptr){
                stk.push_back(root);
                root = root->left;
            }
            root = stk.back();
            stk.pop_back();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};// @lc code=end

