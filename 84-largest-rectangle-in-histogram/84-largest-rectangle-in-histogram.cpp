class Solution {
public:
    
    void nextSmaller(vector<int>& nums,vector<int>& right){
        stack<int> st;
        int n=nums.size();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(st.empty())
                right[i]=n-1;
            else
                right[i]=st.top()-1;
            
            st.push(i);
        }
    }
    void prevSmaller(vector<int>& nums,vector<int>& left){
        stack<int> st;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(st.empty())
                left[i]=0;
            else
                left[i]=st.top()+1;
            
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1)
            return heights[0];
        vector<int> right(n);
        vector<int> left(n);
        
        int ans=0;
        prevSmaller(heights,left);
        nextSmaller(heights,right);
        
        for(int i=0;i<n;i++){
            int val=(right[i]-left[i]+1)*heights[i];
            ans=max(ans,val); 
        }
        
        return ans;
    }
};