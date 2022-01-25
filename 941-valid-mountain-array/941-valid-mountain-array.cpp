class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        bool inc=false,dec=false;
        
        for(int i=0;i<n-1;i++){
            if(!inc&&arr[i]<arr[i+1])
                inc=true;
            if(!dec&&arr[i]>arr[i+1])
                dec=true;
            if(dec&&arr[i]<arr[i+1])
                return false;
            if(arr[i]==arr[i+1])
                return false;
        }
        
        return (dec&&inc);
    }
};