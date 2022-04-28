class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,vector<int>>> pq;
        
        for(int i=0;i<points.size();i++){
            
            double dist=computeDistance(points[i][0],points[i][1]);
            
            pq.push({dist,points[i]});
            
            if(pq.size()>k)
                pq.pop();
            
        }
        
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
    
    double computeDistance(int x,int y){
        int squared=(x*x)+(y*y);
        
        return sqrt(squared);
    }
};