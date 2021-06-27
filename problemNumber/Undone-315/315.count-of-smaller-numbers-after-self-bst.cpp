/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    struct bst_n{
        bst_n *r = nullptr;
        bst_n *l = nullptr;
        int value = 0;
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;

        

        bst_n *node = new bst_n;
        node->value = nums[ nums.size() - 1 ];
        bst_n curNode = *node;
        ans.push_back(0);
        for(int i = nums.size() - 2; i >= 0; i--){
            bst_n *nodeFor = new bst_n;
            nodeFor->value = nums[i];
            if ( nodeFor->value > curNode.value ){
                nodeFor->l = &curNode;
            }else if ( nodeFor->value > curNode.value ){
                nodeFor->r = &curNode;
            }else{
                
            }
            int count = 0;
            bst_n *itNode = new bst_n;
            cout << (nodeFor->l == nullptr);
            // while(nodeFor->l != nullptr){
            //     itNode = nodeFor->l;
            //     count++;
            //     break;
            // }
            
            ans.push_back(count);
            curNode = *nodeFor;
            delete itNode;
        }
        
        return ans;
    }
};
// @lc code=end

