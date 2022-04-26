class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        int visCount=0;
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(vis[curr])
                continue;
            
            vis[curr]=1;
            visCount++;
            cout<<curr<<" "<<visCount<<endl;
            for(int key:rooms[curr])
                    q.push(key);
            
        }
        
        
        if(visCount==n)
            return true;
        
        return false;
        
    }
};