/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(NULL == head){
            return false;
        }
        ListNode *fast = head;
        ListNode *low = head;
        while(fast && low){
            low = low->next;
            if(fast->next){
                fast = fast->next->next;
                if(low == fast){
                return true;
            }
            }
            
        }
        return false;
    }
};
