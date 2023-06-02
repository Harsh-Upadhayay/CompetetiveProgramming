//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    int fun(int val[], int wt[], vector<vector<int>> &dp, int i, int j) {
         
        if(i < 0 || j <= 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(fun(val, wt, dp, i - 1, j), 
                (wt[i] <= j) ? val[i] + fun(val, wt, dp, i - 1, j - wt[i]) : 0);
        
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
       return fun(val, wt, dp, n - 1, W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends