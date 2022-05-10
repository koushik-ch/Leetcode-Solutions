class Solution {
public:
    vector<int> offset={-1,0,1,0,-1};
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)
                    maxGold(grid,i,j,m,n,0,ans);
            }
        }
        
        return ans;
    }
    
    void maxGold(vector<vector<int>>& grid,int i,int j,int m,int n,int curr,int& maxAns){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0)
            return;
        curr+=grid[i][j];
        int temp=grid[i][j];
        
        maxAns=max(maxAns,curr);
        grid[i][j]=0;
        
        for(int x=0;x<4;x++){
            maxGold(grid,i+offset[x],j+offset[x+1],m,n,curr,maxAns);
        }
         grid[i][j]=temp;
    }
};