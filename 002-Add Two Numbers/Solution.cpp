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
        ListNode* res=NULL;
        if(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);            
            pre=res=tmp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            pre->next=tmp;
            pre=tmp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            pre->next=tmp;
            pre=tmp;
            l1=l1->next;
        }
        while(l2){
            sum=l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* tmp=new ListNode(sum);
            pre->next=tmp;
            pre=tmp;
            l2=l2->next;
        }
        if(carry){
            ListNode* tmp=new ListNode(carry);
            pre->next=tmp;
        }
        return res;
    }
};
