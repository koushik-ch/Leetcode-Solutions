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
    void pushToHeap(priority_queue<pair<int,ListNode*>>& pq,vector<ListNode*>& lists){
        for(auto list:lists){
            if(list)
                pq.push({-(list->val),list});
        }
    }
    
    ListNode* getMergedList(priority_queue<pair<int,ListNode*>>& pq){
        ListNode* ans=new ListNode();
        ListNode* temp=ans;
        
        while(!pq.empty()){
            int val=-(pq.top().first);
            ListNode* node=pq.top().second;
            temp->next=new ListNode(val);
            pq.pop();
            if(node->next)
                pq.push({-(node->next->val),node->next});
            temp=temp->next;
        }
        return ans->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>> pq;
        
        pushToHeap(pq,lists);
        ListNode* ans=getMergedList(pq);
        return ans;
    }
};