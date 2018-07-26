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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        //if(headA == headB){
          //  return headA;
        //}
        bool flag = false;
        int redirectA = 0;
        int redirectB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(true){
            if(pA == pB){
                flag = true;
                break;
            }
            if(redirectA >=2 || redirectB >=2){
                break;
            }
            if(pA->next == NULL){
                pA = headB;
                redirectA++;
            }else{
                pA = pA->next;
            }
            if(pB->next == NULL){
                pB = headA;
                redirectB++;
            }else{
                pB = pB->next;
            }
            //headA = 
        }
        if(flag){
            return pA;
        }else{
            return NULL;
        }
    }
};
