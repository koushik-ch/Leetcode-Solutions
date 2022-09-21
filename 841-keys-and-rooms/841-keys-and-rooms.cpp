class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        int visCount=0;
        vector<int> vis(n,0);
        
        return bfs(n,rooms,vis);
    }
    
    bool bfs(int n,vector<vector<int>>& rooms,vector<int>& vis){
        int visCount=0;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int room=q.front();
            q.pop();
            
            if(vis[room])
                continue;
            
            vis[room] = 1;
            visCount++;
            
            
            
            for(int i=0;i<rooms[room].size();i++){
                int newRoom=rooms[room][i];
                    q.push(newRoom);
            }
        }
        if(visCount==n)
                return true;
        return false;
    }
    
};