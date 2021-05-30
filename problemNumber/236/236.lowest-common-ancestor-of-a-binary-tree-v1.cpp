/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == p || root == q){
            return root;
        }else if(root->left == NULL &&root->right == NULL ){
            return NULL;
        }
        TreeNode* leftT;
        TreeNode* rightT;
        if(root->left != NULL){
            leftT = lowestCommonAncestor(root->left, p, q);
        }else {
            leftT = NULL;
        }
        if(root->right != NULL){
            rightT = lowestCommonAncestor(root->right, p, q);
        }else {
            rightT = NULL; 
        }
        
        // if(leftT == NULL){
        //     cout << "Left is None ";
        // }else {
        //     cout << "Left is " << leftT->val;
        // }
        // if(rightT == NULL){
        //     cout << " Right is None ";
        // }else {
        //     cout << " Right is " << rightT->val;
        // }cout << endl;

        if(((leftT == p)&&(rightT == q))||((rightT == p)&&(leftT == q))){
            return root;
        }else if((leftT == q && rightT != p)||(rightT == q && leftT != p)){
            return q;
        }else if((leftT == p && rightT != q)||(rightT == p && leftT != q)){
            return p;
        }else if(leftT!=NULL){
            return leftT;
        }
        else if(rightT!=NULL){
            return rightT;
        }
        else{
            return NULL;
        }
    }
};
// @lc code=end

