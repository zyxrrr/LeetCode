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
    bool isPalindrome(ListNode* head) {
        if(NULL == head){return true;}
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast){
            slow = slow->next;
        }
        ListNode *p = reverseList(slow);
        while(p){
            if(p->val != head->val){
                return false;
            }else{
                p = p->next;
                head = head->next;
            }
        }
        return true;
       
    }
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
