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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first=new ListNode();
        
        first->next=head;
        ListNode* temp=first;
        
        while(first->next&&first->next->next!=NULL){
            ListNode* third=first->next->next;
            first->next->next=third->next;
            third->next=first->next;
            first->next=third;
            first=third->next;
            
        }
        return temp->next;
    }
};