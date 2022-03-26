class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n,string(n,'.'));
        
        solve(n,ans,board,0);
        return ans;
    }
    
    void solve(int n,vector<vector<string>>& ans,vector<string>& board,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isValid(board,row,col,n)){
                board[row][col]='Q';
                solve(n,ans,board,col+1);
                board[row][col]='.';
            }
        }
    }
    
    bool isValid(vector<string>& board,int row,int col,int n){
        int rowCopy=row;
        int colCopy=col;
        
        while(row>=0&&col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=rowCopy;
        col=colCopy;
        
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        col=colCopy;
        
        while(col>=0&&row<n){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
};