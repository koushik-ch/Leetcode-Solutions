class Solution {
public:
    int addDigits(int num) {
       int sum=0;
        int numCopy=num;
        
        while(numCopy){
            sum+=numCopy%10;
            numCopy/=10;
            
        }
        if(sum<10)
            return sum;
        return addDigits(sum);
    }
};