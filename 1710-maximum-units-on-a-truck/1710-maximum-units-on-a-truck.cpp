class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {return a[1] > b[1];});
        
        int ans = 0;
        for(auto x : boxTypes) {
            if(truckSize <= x[0]) {
                ans += truckSize * x[1];
                break;
            }
            
            truckSize -= x[0];
            ans += x[0] * x[1];
        }
        
        
        return ans;
    }
};