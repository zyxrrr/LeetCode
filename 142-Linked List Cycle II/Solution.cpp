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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode *H = new ListNode(0);
        H->next = head;
        head = H;
        int len = 0;
        bool res = false;
        ListNode *fast = head;
        ListNode *low = head;
        while(fast && low){
            low = low->next;
            if(fast->next){
                fast = fast->next->next;
                if(low == fast){
                    //return low;
                    res = true;
                    break;
                }
            }            
        }
        
        if(res){
            while(low){
                low = low->next;
                len++;
                if(low == fast){break;}
            }
        }else{
            return NULL;
        }
        
        fast = low = head;
        while(len){
            fast = fast->next;
            len--;
        }
        while(fast && low){
            fast = fast->next;
            low = low->next;
            if(fast == low){
                return fast;
            }
        }
        return NULL;
    }
};
