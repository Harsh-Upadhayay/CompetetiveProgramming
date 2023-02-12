//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        
        vector<int> preSum(n, arr[0]);
        for(int i = 1; i < n; i++) preSum[i] = preSum[i - 1] + arr[i];
        
        map<int, int> mp;
        int len = 0, maxLen = 0;
        
        for(int i = 0; i < n; i++) {
         
            if(preSum[i] == 0)
                maxLen = max(maxLen, i + 1);
            
            if(mp.find(preSum[i]) == mp.end())
                mp[preSum[i]] = i;
            else
                maxLen = max(maxLen, i - mp[preSum[i]]);
            
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends