// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int flag=0;
        
        int num=0;
        
        for(int i=0;i<s.length();i++){
            if(i==0&&s[i]=='-')
                flag=1;
            else if(s[i]>='0'&&s[i]<='9'){
                num*=10;
                num+=(s[i]-'0');
            }
            else
                return -1;
        }
        if(flag)
        return -num;
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends