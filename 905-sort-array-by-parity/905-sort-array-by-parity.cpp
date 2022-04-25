class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int oddPtr=n-1,evenPtr=0;
        
        while(evenPtr<oddPtr){
            if(nums[evenPtr]%2==0)
                evenPtr++;
            
            else{
                swap(nums[oddPtr],nums[evenPtr]);
                oddPtr--;
            }
        }
        return nums;
    }
};