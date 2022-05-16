class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> path(n,vector<int>(m,0));
        
        path=grid;
        if(path[0][0]==1)
            return -1;
        
        path[0][0]=1;
        
        q.push({0,0});
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            if(x==n-1&&y==m-1)
                return path[x][y];
            q.pop();
            int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
            int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
            
            for(int i=0;i<8;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                
                if(newX>=0&&newX<n&&newY>=0&&newY<m&&path[newX][newY]==0){
                    q.push({newX,newY});
                    path[newX][newY]=1+path[x][y];
                    if(newX==n-1&&newY==m-1)
                        return path[newX][newY];
                }
            }
        }
        return -1;
    }
};