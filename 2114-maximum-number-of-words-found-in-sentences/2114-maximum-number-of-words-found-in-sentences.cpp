class Solution {

    int words(string str) {
        int ans = 0;
        for(char ch : str)
            ans += (ch == ' ');
        return ans + 1;
    }
    
    public:
    
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string str : sentences) 
            ans = max(ans, words(str));
        return ans;
    }
};