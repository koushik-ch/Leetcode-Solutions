class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis,n);
                count++;
            }
        }
        return count;
    }
    
    void dfs(int u,vector<vector<int>>& adj,vector<bool>& vis,int n){
        
        vis[u]=true;
        for(int i=0;i<n;i++){
            
            if(!vis[i]&&adj[u][i])
                dfs(i,adj,vis,n);
            
        }
    }
};