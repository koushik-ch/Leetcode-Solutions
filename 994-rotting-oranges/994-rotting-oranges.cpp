class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
    int freshCount=0,timeTaken=0;
    queue<pair<int,int>> q;
    
    vector<int> delta={-1,0,1,0,-1};
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
                q.push({i,j});
            else if(grid[i][j]==1)
                freshCount++;
        }
    }
    
    while(!q.empty()&&freshCount>0){
        int size=q.size();
        
        for(int i=0;i<size;i++){
            pair<int,int> currRottenApple=q.front();
            q.pop();
            
            for(int x=0;x<4;x++){
                int dx=currRottenApple.first+delta[x];
                int dy=currRottenApple.second+delta[x+1];
                
                if(dx<0||dx>=m||dy<0||dy>=n||grid[dx][dy]!=1)
                    continue;
                q.push({dx,dy});
                grid[dx][dy]=2;
                freshCount--;
            }
        }
        timeTaken++;
    }
    
    
    if(freshCount>0)
        return -1;
    
    return timeTaken;
    }
};;