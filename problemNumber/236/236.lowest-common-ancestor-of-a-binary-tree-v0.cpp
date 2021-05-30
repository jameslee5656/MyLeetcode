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
        vector<TreeNode*> vt;
        TreeNode *curr = new TreeNode;
        curr = root;
        vt.push_back(curr);
        vector<TreeNode*> :: iterator vi;
        vi = vt.begin();
        while(vi != vt.end()){
            if((*vi)->left != nullptr) vt.push_back((*vi)->left);
            if((*vi)->right != nullptr) vt.push_back((*vi)->right);

            cout << (*vi)->val << " " << vt[0]->val << endl;
            
            for(auto v:vt){
                cout << v->val << " ";
            }cout << endl << "------------" << endl;
            // vt.deque();
            if(curr == p || curr == q){
                cout << "Find the node: " << (*vi)->val << endl;
                break;
            }
            // vt.erase(vt.begin());
            vi++;
            if(vi == vt.end()){
                break;
            }
        }
        // delete curr;

        return root;
    }
};
// @lc code=end

