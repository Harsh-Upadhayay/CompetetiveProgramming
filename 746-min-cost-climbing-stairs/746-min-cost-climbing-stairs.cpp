
class Solution {
    
     int dp[1000000];

public:
    
    
    int mc(vector<int>& cost, int i = 0) {
        
        if(dp[i] == -1) {
            if(i == cost.size()) 
                dp[i] = 0;

            else if(i > cost.size())
                dp[i] = 100000;

            else

            dp[i] =  min(mc(cost, i + 1) + cost[i], 
                         mc(cost, i + 2) + cost[i]);
        }
                    
        return dp[i];
        
    }
    
    int minCostClimbingStairs(vector<int> &cost) {
        
        memset(dp, -1, 1000000);
        int a = mc(cost, 0);
        memset(dp, -1, 1000000);
        int b = mc(cost, 1);        
        return min(a, b);
    }
};