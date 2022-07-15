class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1)
                    count=max(solve(i,j,grid),count);
            }
        }
        if(count==INT_MIN)
            return 0;
        return count;
    }
    
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        return 1+
            solve(i+1,j,grid)+
            solve(i-1,j,grid)+
            solve(i,j+1,grid)+
            solve(i,j-1,grid);
        
    }
};