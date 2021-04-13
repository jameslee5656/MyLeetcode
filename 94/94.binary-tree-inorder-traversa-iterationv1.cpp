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
        if (root == nullptr) return {};
        vector<TreeNode*> stk;
        vector<int> result;
        TreeNode* curr = root;
        while(!stk.empty()||curr!=nullptr){
            while(curr != nullptr){
                stk.push_back(curr);
                curr = curr->left;
            }
            curr = stk.back(); stk.pop_back();
            // cout << root->val << " " << endl;
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};
// @lc code=end

