class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ind=upperBound(letters,target);
        
        if(ind==letters.size())
            return letters[0];
        
        return letters[ind];
    }
    
    
    int upperBound(vector<char>& letters,char target){
        int low=0,high=letters.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(letters[mid]<=target)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};