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
    ListNode* reverseList(ListNode* head) {
        ListNode *next = NULL;
        ListNode *pre = head;
        while(head){
            next = head->next;
            if(next){
                head->next = next->next;
                next->next = pre;
                pre = next;
            }else{
                break;
            }
            //head = head->next;
        }
        return pre;
    }
};
