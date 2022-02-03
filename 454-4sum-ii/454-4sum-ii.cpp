class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        int count=0;
        for(int a:A){
            for(int b:B){
                mp[a+b]++;
            }
        }
        
        for(int c:C){
            for(int d:D){
                if(mp.count(0-c-d)>0)
                    count+=mp[0-c-d];
            }
        }
        return count;
    }
};