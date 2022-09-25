class Solution {
    
    set<int> ans;
    int num;
    
    void dfs(int i, int n, int k) {
        if(n == 0) {
            ans.insert(num);
            return;
        };
    
        num = num * 10 + i;
        
        i = i + k;
        if(i <= 9) 
            dfs(i, n - 1, k);
        
        i = i - 2 * k;
        if(i >= 0)
            dfs(i, n - 1, k);
        num /= 10;
        
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i = 1; i <= 9; i++)
            dfs(i, n, k);
        vector<int> v;
        for(auto x : ans) v.push_back(x);
        return v;        
    }
};