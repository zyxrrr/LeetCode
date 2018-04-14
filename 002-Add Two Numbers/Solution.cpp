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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,carry=0;
        ListNode* pre=NULL;
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            tmp->next=pre;
            pre=tmp;
        }
        while(l1){
            sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            tmp->next=pre;
            pre=tmp;
        }
        while(l2){
            sum=l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            tmp->next=pre;
            pre=tmp;
        }
        if(carry){
            ListNode* tmp=new ListNode(carry);
            tmp->next=pre;
            pre=tmp;
        }
        return pre;
    }
};
