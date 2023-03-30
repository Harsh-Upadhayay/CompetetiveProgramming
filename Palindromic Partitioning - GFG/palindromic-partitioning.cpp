//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define inf ((int)1e8)
class Solution{
    
    bool isPall(string &str, int i, int j) {
        
        if(j == str.size())
            j--;
        
        if(i >= j) return true;
        
        return str[i] == str[j] ? isPall(str, i + 1, j - 1) : false;
        
    }
    
    int fun(string &str, vector<vector<int>> &dp, int i, int j) {
        
        int n = str.size();
        if(i < 0) {
            
            if(isPall(str, 0, j))
                return 0;
            else
                return inf;
            
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int take = inf, nottake = inf;
        
        nottake = fun(str, dp, i - 1, j);
        
        if(j == n) {
            if(isPall(str, i, n - 1))
                take = 1 + fun(str, dp, i - 1, i - 1);
        }
        else if(isPall(str, i, j))
            take = 1 + fun(str, dp, i - 1, i - 1);
            
        return dp[i][j] = min(take, nottake);
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        string curStr = "";
        return fun(str, dp, n - 1, n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends