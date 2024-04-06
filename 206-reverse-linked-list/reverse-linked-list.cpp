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
        
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next_node = nullptr;
        
        while (current != nullptr) {
            // Store the next node
            next_node = current->next;
            // Reverse the current node's pointer
            current->next = previous;
            // Move pointers one step forward
            previous = current;
            current = next_node;
        }
        
        // The new head of the reversed list is the last node processed
        head = previous;
        
        return head;
    }
};
