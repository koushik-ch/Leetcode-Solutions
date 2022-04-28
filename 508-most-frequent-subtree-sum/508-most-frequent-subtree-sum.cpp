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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        
        int maxFreq=0;
        sumFreq(root,maxFreq,mp);
        
        vector<int> ans;
        
        for(auto it:mp){
            if(it.second==maxFreq)
                ans.push_back(it.first);
        }
        return ans;
    }
    int sumFreq(TreeNode* root,int& maxFreq,unordered_map<int,int>& mp){
        if(!root)
            return 0;
        
        int sum=root->val+sumFreq(root->left,maxFreq,mp)+sumFreq(root->right,maxFreq,mp);
        
        mp[sum]++;
        maxFreq=max(maxFreq,mp[sum]);
        return sum;
        
    }
};