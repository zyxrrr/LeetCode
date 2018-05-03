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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* H=new ListNode(0);
        H->next=head;
        ListNode* tmp=head;
        ListNode* del=H;
        while(n-1){
            tmp=tmp->next;
            n--;
        }
        while(tmp->next!=NULL){
            del=del->next;
            tmp=tmp->next;
        }
        tmp=del->next;
        del->next=del->next->next;
        delete tmp;
        return H->next;
    }
};
