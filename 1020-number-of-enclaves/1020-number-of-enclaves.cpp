class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]==1)
                dfs(board,i,0,m,n);
            if(board[i][n-1]==1)
                dfs(board,i,n-1,m,n);
        }
        
        for(int j=0;j<n;j++){
            if(board[0][j]==1)
                dfs(board,0,j,m,n);
            if(board[m-1][j]==1)
                dfs(board,m-1,j,m,n);
        }
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(board[i][j]==1)
                    ans++;
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& board,int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=1)
            return;
        
        board[i][j]=0;
        
        dfs(board,i+1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i,j-1,m,n);
        dfs(board,i-1,j,m,n);
    }
};