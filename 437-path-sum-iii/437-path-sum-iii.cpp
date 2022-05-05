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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        int count=0;
        
        countPaths(root,mp,targetSum,0,count);
        return count;
    }
    
    void countPaths(TreeNode* root,unordered_map<long long,int>& mp,int target,long long sum,int& count){
        if(!root)
            return;
        
        sum+=root->val;
        
        if(sum==target)
            count++;
        
            if(mp.find(sum-target)!=mp.end())
                count+=mp[sum-target];
        
        mp[sum]++;
        
        countPaths(root->left,mp,target,sum,count);
        countPaths(root->right,mp,target,sum,count);
        mp[sum]--;
    }
};
