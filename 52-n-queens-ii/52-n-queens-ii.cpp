class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        
        vector<int> ud(2*n,0);
        vector<int> ld(2*n,0);
        vector<int> rowHash(n,0);
        int count=0;
        
        solve(board,0,n,ud,ld,rowHash,count);
        return count;
        
    }
    
    void solve(vector<string>& board,int col,int n,vector<int>& ud,vector<int>& ld,vector<int>& rowHash,int& count){
        if(col==n){
            count++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(!ld[row+col]&&!ud[n+(row-col)]&&!rowHash[row]&&board[row][col]=='.'){
                ld[row+col]=1;
                ud[n+(row-col)]=1;
                rowHash[row]=1;
                
                board[row][col]='Q';
                
                solve(board,col+1,n,ud,ld,rowHash,count);
                
                board[row][col]='.';
                ld[row+col]=0;
                ud[n+(row-col)]=0;
                rowHash[row]=0;
            }
        }
        
    }
};