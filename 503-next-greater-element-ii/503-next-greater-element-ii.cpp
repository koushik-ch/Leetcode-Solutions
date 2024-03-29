class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        
        for(int i=(n*2)-1;i>=0;i--){
            while(st.size()&&st.top()<=nums[i%n])
                st.pop();
            if(!st.empty())
                res[i%n]=st.top();
            

            st.push(nums[i%n]);
        }
        return res;
    }
};