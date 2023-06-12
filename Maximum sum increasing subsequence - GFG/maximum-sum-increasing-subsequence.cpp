//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	
	int fun(int arr[], vector<vector<int>> &dp, int n, int i, int j) {
	    
	   // cout << n << " ";
	    if(i < 0)
	        return 0;
	        
	    if(dp[i][j] != -1)
	        return dp[i][j];
	       
	   int take;
	   if((j == n || arr[j] > arr[i])) {
	        take = arr[i] + fun(arr, dp, n, i - 1, i);
	       // cout << arr[j] <<  " " << arr[i] << "\n";
	   }
	   else
	        take = 0;
	       
	    return dp[i][j] = max(fun(arr, dp, n, i - 1, j),
	                        take);
	    
	}

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return fun(arr, dp, n, n - 1, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends