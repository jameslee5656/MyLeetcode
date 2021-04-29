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
        vector<TreeNode> stack;
        vector<int> result;
        while(!stack.empty()||root!=nullptr){
            while(root != nullptr){
                stack.push_back(root);
                root = root->left;
            }
            root = stack.pop();
            result.push_back(root.val);
            root = root.right;
        }
        return result;
    }
};