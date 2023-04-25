//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int fun(int arr[], vector<vector<int>> &dp, int i, int j) {
        if(j == i)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1e9;
        
        for(int k = i; k < j; k++)
            ans = min(ans, (arr[i - 1] * arr[k] * arr[j]) + fun(arr, dp, i, k) + fun(arr, dp, k + 1, j));
            
        return dp[i][j] = ans;
        
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        
        for(int i = N - 1; i >= 1; i--) {
            
            for(int j = 1; j <= N - 1; j++) {
                
                if(i == j) continue;
                
                   int ans = 1e9;
        
                    for(int k = i; k < j; k++)
                        ans = min(ans, (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j]);
                        
                    dp[i][j] = ans;
        
                
            }
            
        }
        
        return dp[1][N - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends