class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> ld(2*n,0);
        vector<int> ud(2*n,0);
        vector<int> rowHash(n,0);
        
        vector<vector<string>> ans;
        
        vector<string> board(n,string(n,'.'));
        
        solve(n,ans,board,0,ld,ud,rowHash);
        return ans;
    }
    
    void solve(int n,vector<vector<string>>& ans,vector<string>& board,int col,vector<int>& ld,vector<int>& ud,vector<int>& rowHash){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(!rowHash[row]&&!ld[row+col]&&!ud[n+(row-col)]){
                board[row][col]='Q';
                
                rowHash[row]=1;
                ld[row+col]=1;
                ud[n+(row-col)]=1;
                
                solve(n,ans,board,col+1,ld,ud,rowHash);
                board[row][col]='.';
                
                rowHash[row]=0;
                ld[row+col]=0;
                ud[n+(row-col)]=0;
            }
        }
    }
    

};