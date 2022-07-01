class Solution {
public:
    
    static bool comparator(vector<int>& box1,vector<int>& box2){
        return box1[1]>=box2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        
        int i=0,ans=0;
        
        while(i<boxTypes.size()&&truckSize){
            if(truckSize<boxTypes[i][0]){
                ans+=(truckSize*boxTypes[i][1]);
                truckSize=0;
            }
            else{
                ans+=(boxTypes[i][1]*boxTypes[i][0]);
                    truckSize-=boxTypes[i][0];
            }
            i++;
        }
        return ans;
    }
};