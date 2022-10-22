class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
    
        int n = arr.size();
        vector<int> next(n + 1, 0), curr(next);

        for(int i = n - 1; i >= 0; i--, next = curr) {
            for(int j = i - 1; j >= -1; j--) {

                int len = next[j + 1];
                if(j == -1 || arr[j] < arr[i])
                    len = max(len, 1 + next[i + 1]);
                curr[j + 1] = len;
            }
        }

        return next[0];
    }
  
};