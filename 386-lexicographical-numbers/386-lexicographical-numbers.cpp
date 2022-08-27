class Solution {
    
    void dfs(int i, int n, vector<int> &v) {
        if(i > n)
            return;
        v.push_back(i);
        int num = 0;
        for(int j = 0; j < 10 && num < n; j++) {
            num = i * 10 + j;
            dfs(num, n, v);
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> v;
        
        for(int i = 1; i < 10; i++)     
            dfs(i, n, v);
                
        return v;
    }
};