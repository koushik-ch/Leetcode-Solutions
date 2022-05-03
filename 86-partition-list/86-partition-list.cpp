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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1=new ListNode();
        
        ListNode* l2=new ListNode();
        
        ListNode* l1head=l1;
        ListNode* l2head=l2;
        ListNode* dummy=head;
        
        while(dummy){
            if(dummy->val<x){
                l1->next=dummy;
                l1=l1->next;
            }
            else{
                l2->next=dummy;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        l1->next=l2head->next;
        l2->next=NULL;
        return l1head->next;
    }
};