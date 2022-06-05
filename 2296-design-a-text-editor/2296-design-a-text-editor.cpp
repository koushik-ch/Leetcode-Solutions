class TextEditor {
public:
    deque<char> left,right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char i:text)
            left.push_back(i);
    }
    
    int deleteText(int k) {
        int ans=0;
        while(k&&left.size()){
            k--;
            left.pop_back();
            ans++;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        string ans;
        
        while(k&&left.size()){
            right.push_front(left.back());
            k--;
            left.pop_back();
        }
        
        int n=left.size()-1;
        
        for(int ind=n,i=0;i<10;i++,ind--){
            if(ind<0)
                break;
            ans+=left[ind];
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        while(k&&right.size()){
            left.push_back(right.front());
            right.pop_front();
            k--;
        }
        
        string ans;
        
        int n=left.size()-1;
        
        for(int i=0,ind=n;i<10;i++,ind--){
            if(ind<0)
                break;
            ans+=left[ind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */