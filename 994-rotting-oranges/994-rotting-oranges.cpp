class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        vector<int> change={-1,0,1,0,-1};
        
        int orangeCount=0;
        int m=grid.size(),n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    orangeCount++;
                
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int minutes=-1;
        if(orangeCount==0)
            return 0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                
            pair<int,int> curr=q.front();
        
            q.pop();
            
            for(int i=0;i<4;i++){
                int x=curr.first+change[i];
                int y=curr.second+change[i+1];
                if(x<0||y<0||x==m||y==n||grid[x][y]!=1)
                    continue;
                q.push({x,y});
                grid[x][y]=2;
                 orangeCount--;
            }
            // grid[curr.first][curr.second]=2;
           
                
            }
            minutes++;
            
        }
        
        if(orangeCount)
            return -1;
        
        return minutes;
        
    }
};;