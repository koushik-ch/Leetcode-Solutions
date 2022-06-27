class Solution {
public:
    int minPartitions(string n) {
        int maxVal=0;
        
        for(char c:n){
            if(c-'0'>maxVal)
                maxVal=c-'0';
        }
        return maxVal;
    }
};