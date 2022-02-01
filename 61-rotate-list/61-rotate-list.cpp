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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k||!head||!head->next)
            return head;
        
        int size=1;
        ListNode* temp=head;
        while(temp&&temp->next){
            size++;
            temp=temp->next;
        }
        
        k=k%size;
        
        if(k==0) return head;
        k=size-k;
        temp->next=head;
        temp=head;
        while(k-->1)
            temp=temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};