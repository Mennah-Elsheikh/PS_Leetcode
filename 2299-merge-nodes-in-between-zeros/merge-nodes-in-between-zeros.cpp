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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to help with list construction
        ListNode* current = dummy;         // Pointer to the current node in the result list
        int sum = 0;                       // Sum of values between zeros
        
        head = head->next;                 // Skip the initial zero
        while (head) {
            if (head->val == 0) {
                // Create a new node with the sum and reset the sum
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0;
            } else {
                sum += head->val;
            }
            head = head->next;
        }
        
        return dummy->next; // Return the next node of dummy as the head of the result list
    }
};
