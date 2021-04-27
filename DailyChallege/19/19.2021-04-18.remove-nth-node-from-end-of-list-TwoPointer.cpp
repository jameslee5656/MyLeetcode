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
        ListNode dummy;
        ListNode* slow = &dummy; ListNode* fast = &dummy;
        dummy.val = -1;
        dummy.next = head;
        int ncur = 0;
        // cout << "Debug" << endl;
        while(fast->next != nullptr){
            if(ncur != n) ncur++;
            else slow = slow->next;
            fast = fast->next;
        }

        // fast = slow->next;
        slow->next = slow->next->next;
        
        // }else if(ncur < n && fast == nullptr)){
        //     fast = nullptr;
        //     slow->next = fast;
        // }
        
        return dummy.next;
    }
};
// @lc code=end

