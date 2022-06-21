class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int sum=bricks;
        
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                int diff=heights[i]-heights[i-1];
                pq.push(-1*diff);
                
                if(pq.size()>ladders){
                    int val=-1*pq.top();
                    pq.pop();
                    
                    if(val>sum)
                        return i-1;
                    sum-=val;
                }
            }
        }
        return heights.size()-1;
    }
};