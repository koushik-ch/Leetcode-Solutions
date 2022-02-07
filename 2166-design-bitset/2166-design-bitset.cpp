class Bitset {
public:
    vector<int> arr;
    bool flipp;
    int cnt;
    Bitset(int size) {
        arr.resize(size);
        cnt=0;
        flipp=false;
    }
    
    void fix(int idx) {
        if(!flipp){
            if(arr[idx]==0)
                cnt++;
            arr[idx]=1;
        }
        
        else{
            if(arr[idx]==1)
                cnt++;
            arr[idx]=0;
        }
        
    }
    
    void unfix(int idx) {
        if(!flipp){
            if(arr[idx]==1)
                cnt--;
            arr[idx]=0;
        }
        else{
            if(arr[idx]==0)
                cnt--;
            arr[idx]=1;
        }
        
    }
    
    void flip() {
        flipp=!flipp;
        cnt=arr.size()-cnt;
    }
    
    bool all() {
        
        if(cnt==arr.size())
            return true;
        return false;
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string ans="";
          
        if(!flipp){
            for(auto it:arr){
                if(it==0) ans+='0';
                else
                    ans+='1';
            }
        }
        else{
            for(auto it:arr){
                if(it==0) ans+='1';
                else
                    ans+='0';
            }
        }
        
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */