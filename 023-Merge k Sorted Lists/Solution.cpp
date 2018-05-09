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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *HEAD = new ListNode(0);
        ListNode *tmp=HEAD;
        while(!lists.empty()){
            if(lists[0]==NULL){
                lists.erase(lists.begin());
                continue;
            }
            int min=lists[0]->val;
            int idx=0;
            int i=1;
            for(;i < lists.size();i++){
                /*
                if(lists[i]==NULL){
                    lists.erase(lists.begin()+i);
                    continue;
                }
                */
                if(lists[i]!=NULL && lists[i]->val < min){
                    min=lists[i]->val;
                    idx=i;
                }
            }
            tmp->next = lists[idx];
            tmp=tmp->next;
            lists[idx] = lists[idx]->next;
            if(lists[idx]==NULL){
                lists.erase(lists.begin()+idx);
            }
        }
        return HEAD->next;
    }
};
