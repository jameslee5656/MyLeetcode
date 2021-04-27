/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curNode = head;
        vector<ListNode*> rec;
        while(curNode != nullptr){
            rec.push_back(curNode);
            curNode = curNode->next;
        }
        if((rec.size() - n > 0)&&(rec.size()-1 > rec.size() - n))rec[rec.size() - n - 1]->next = rec[rec.size() - n + 1];
        else if(rec.size() - n == 0) head = head->next;
        else if(rec.size() - n <= rec.size() -1){
            rec.pop_back();
            rec.back()->next = nullptr;
        }
        else cout << "Something wrong" << endl;
        return head;
    }
};
// @lc code=end

