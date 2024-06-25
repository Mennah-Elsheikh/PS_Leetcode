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
    ListNode* reverseList(ListNode* head) {
        // If the list is empty or has only one node, no need to reverse
        if (head == nullptr || head->next == nullptr)
            return head;  
       ListNode* reversedlisthead = reverseList(head->next);
       head->next->next = head;
       head->next = nullptr;
       return reversedlisthead ;
    }
};
