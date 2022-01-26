/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        getElements(root1,list1);
        getElements(root2,list2);
        
        return mergeLists(list1,list2);
    }
    
    void getElements(TreeNode* root,vector<int>& list){
        if(!root)
            return;
        getElements(root->left,list);
        list.push_back(root->val);
        getElements(root->right,list);
    }
    vector<int> mergeLists(vector<int>& list1,vector<int>& list2){
        int ptr1=0,ptr2=0;
        int n1=list1.size(),n2=list2.size();
        vector<int> res;
        
        while(ptr1<n1&&ptr2<n2){
            if(list1[ptr1]<=list2[ptr2]){
                res.push_back(list1[ptr1]);
                ptr1++;
            }
            else{
                res.push_back(list2[ptr2]);
                ptr2++;
            }
        }
        while(ptr1<n1){
            res.push_back(list1[ptr1]);
            ptr1++;
        }
        while(ptr2<n2){
            res.push_back(list2[ptr2]);
            ptr2++;
        }
        return res;
    }
};