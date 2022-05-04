class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char val=board[i][j];
                    board[i][j]='.';
                    if(!validate(board,i,j,val))
                        return false;
                }
            }
        }
        return true;
    }
    
    bool validate(vector<vector<char>>& board,int row,int col,char val){
        
        for(int i=0;i<9;i++){
            if(board[i][col]==val)
                return false;
            
            if(board[row][i]==val)
                return false;
            
            int rowVal=3*(row/3)+(i%3);
            
            int colVal=3*(col/3)+(i/3);
            
            if(board[rowVal][colVal]==val)
                return false;
        }
        
        return true;
        
    }
};