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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        
        int count=k;
        findKthSmallest(root,ans,count);
        
        return ans;
    }
    
    void findKthSmallest(TreeNode* root,int& ans,int& count){
        if(!root)
            return;
        
        findKthSmallest(root->left,ans,count);
        
        count--;
        
        if(count==0)
            ans=root->val;
        
        // count--;
        findKthSmallest(root->right,ans,count);
        
    }
};