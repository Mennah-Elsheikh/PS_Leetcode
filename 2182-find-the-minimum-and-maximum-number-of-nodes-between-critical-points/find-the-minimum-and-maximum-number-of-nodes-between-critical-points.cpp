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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head ;
        ListNode* cur = head-> next ; 
        int index = 0  , last = -1 , curr = -1 , mini; 
        int minians = INT_MAX , maxans = - 1;
        while(cur->next)
        {
            if(cur-> val > prev->val && cur-> val > cur->next->val || 
            cur-> val < prev->val && cur-> val < cur->next->val)
            {
                if(curr == -1 )
                {
                    curr = mini = index ; 
                }
                else
                {
                    last = curr ;
                    curr = index ; 
                    minians = min( minians , curr - last );
                    maxans = max( maxans , curr - mini);
                }
            }
            index++ ; 
            prev = prev->next; 
            cur = cur->next;
        }
        if(minians == INT_MAX )
        {
            minians = -1;
        }
        return {minians , maxans };
    }
};