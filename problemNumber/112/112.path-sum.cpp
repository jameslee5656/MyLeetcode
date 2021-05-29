/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    int sum = 0;
    bool targetFlag = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        // cout << (root==nullptr) << endl;
        // cout << (root==nullptr) << endl;
        if(root==nullptr){
            return false;
        }
        // cout << root->left->val << endl;
        // vector<int> vec;
        // int sum = 0;
        // cout << "Debug Here" << endl;

        TreeNode* curr = new TreeNode;
        curr = root;
        int layer = 0;
        dfs(curr,targetSum,layer);
        // delete curr;
        return targetFlag;
    }
    void dfs(TreeNode* curr,int targetSum,int layer){
        if(curr==NULL){
            return;
        }
        if(curr->left == NULL && curr->right==NULL){
            sum+=curr->val;
            if(sum == targetSum){
                targetFlag = true;
            }
            sum-=curr->val;
            return;
        }
        else{
            sum+=curr->val;
            layer++;
            // cout << "before left "<<sum << " cur val: " << curr->val<< endl;
            dfs(curr->left,targetSum,layer);
            sum-=curr->val;
            layer--;
            // cout << "after left "<< sum << " cur val: " << curr->val <<  endl;

            // cout << "before right "<<sum << " cur val: " << curr->val<< endl;
            sum+=curr->val;
            layer++;
            dfs(curr->right,targetSum,layer);
            sum-=curr->val;
            layer--;
            // cout << "after right "<<sum << " cur val: "<< curr->val << endl;
        }
        

    }
};
// @lc code=end

