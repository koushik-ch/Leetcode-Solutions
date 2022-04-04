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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* last=head;
        ListNode* beg=head;
        int i=1;
        
        while(beg->next&&i<k){
            beg=beg->next;
            i++;
        }
        ListNode* dummy=beg;
        
        while(dummy->next){
            last=last->next;
            dummy=dummy->next;
        }
        swap(last->val,beg->val);
        return head;
    }
};