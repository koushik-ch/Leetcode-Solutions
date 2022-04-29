class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> res(n);
        
        for(int i=0;i<n;i++)
            res[i]=dfs(grid,0,i,m,n);
        return res;
    }
    
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i==m){
            cout<<i<<" "<<j<<endl;
            return j;
        }
        if(isValid(i,j,m,n)){
            
            int val=grid[i][j];
            
            if(isValid(i,j+val,m,n)&&grid[i][j]==grid[i][j+val])
                return dfs(grid,i+1,j+val,m,n);
            
        }
        return -1;
    }
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0||j<0||i>=m||j>=n);
    }
};