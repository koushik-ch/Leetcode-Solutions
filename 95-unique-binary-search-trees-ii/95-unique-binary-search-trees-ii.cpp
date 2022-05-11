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
    vector<TreeNode*> generateTrees(int n) {
        return createTrees(1,n);
        
    }
    
    vector<TreeNode*> createTrees(int l,int r){
        vector<TreeNode*> list;
        
        if(l>r){
            list.push_back(NULL);
            return list;
        }
        if(l==r){
            list.push_back(new TreeNode(l));
            return list;
        }
        
        for(int i=l;i<=r;i++){
            vector<TreeNode*> left=createTrees(l,i-1);
            vector<TreeNode*> right=createTrees(i+1,r);
            
            for(TreeNode* leftRoot:left){
                for(TreeNode* rightRoot:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftRoot;
                    root->right=rightRoot;
                    
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};