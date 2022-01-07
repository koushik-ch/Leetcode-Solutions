class Solution {
public:
    
    vector<int> mergeSort(vector<int>& nums){
        int n=nums.size();
        if(n==1)
            return nums;
        int mid=n/2;
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<mid;i++)
            left.push_back(nums[i]);
        for(int i=mid;i<n;i++)
            right.push_back(nums[i]);
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        merge(nums,left,right);
        return nums;
    }
    
    void merge(vector<int>& nums,vector<int>& left,vector<int>& right){
        int leftSize=left.size(),rightSize=right.size();
        int l=0,r=0,i=0;
        
        while(l<leftSize&&r<rightSize){
            if(left[l]<=right[r]){
                nums[i]=left[l];
                l++;
            }
            else{
                nums[i]=right[r];
                r++;
            }
            i++;
        }
        
        while(l<leftSize){
            nums[i]=left[l];
            l++;
            i++;
        }
        while(r<rightSize){
            nums[i]=right[r];
            r++;
            i++;
        }
        
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};
