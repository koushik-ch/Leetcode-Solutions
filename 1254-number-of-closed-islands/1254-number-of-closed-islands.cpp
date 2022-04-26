class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size(),count=0;
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0)
                removeNonClosed(grid,i,0,m,n);
            if(grid[i][n-1]==0)
                removeNonClosed(grid,i,n-1,m,n);
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i]==0)
                removeNonClosed(grid,0,i,m,n);
            if(grid[m-1][i]==0)
                removeNonClosed(grid,m-1,i,m,n);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                    exploreClosed(grid,i,j,m,n);
                }
            }
        }
        return count;
        
    }
    
    void exploreClosed(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=0)
            return;
        grid[i][j]=1;
        
        exploreClosed(grid,i+1,j,m,n);
        exploreClosed(grid,i-1,j,m,n);
        exploreClosed(grid,i,j+1,m,n);
        exploreClosed(grid,i,j-1,m,n);
    }
    
    void removeNonClosed(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=0)
            return;
        
        grid[i][j]=2;
        
        removeNonClosed(grid,i+1,j,m,n);
        removeNonClosed(grid,i,j+1,m,n);
        removeNonClosed(grid,i,j-1,m,n);
        removeNonClosed(grid,i-1,j,m,n);
    }
};