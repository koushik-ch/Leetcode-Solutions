class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size(), sum = 0;
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;
        
        // finding min values on left        
        for(int i = 0; i < n; i++){            
            int cnt = 1;
            while(!st.empty() && arr[i] < st.top().first){
                cnt += st.top().second;
                st.pop();
            }
            
            st.push(make_pair(arr[i], cnt));
            left[i] = cnt;
        }
        
        while(!st.empty()) st.pop();
        
        // finding min values on right        
        for(int i = n-1; i >= 0; i--){            
            int cnt = 1;
            
            // Here checking if its greater than equal to bcz, if same element is there then also we need to pop it, i.e => [71,55,82,55]
            while(!st.empty() && arr[i] <= st.top().first){
                cnt += st.top().second;
                st.pop();
            }
            
            st.push(make_pair(arr[i], cnt));
            right[i] = cnt;
        }
                
        for(int i = 0; i < n; i++){
            long leftRight = (left[i] * right[i]) % 1000000007;
            int temp = (arr[i] * leftRight) % 1000000007;
            sum = (sum + temp) % 1000000007;
        }
        
        return sum;
    }
};