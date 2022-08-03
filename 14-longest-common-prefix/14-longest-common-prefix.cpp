class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = "";
        int n = INT_MAX;
        for(auto x : strs) n = min(n, (int)x.size());
        
        for(int j = 0; j < n; j++) {
            bool flag = true;
            
            for(int i = 0; i < strs.size(); i++){
                cout << strs[i][j] << " ";
                flag &= (strs[i][j] == strs[0][j]);
            }
            cout << endl;
            if(flag) pre += strs[0][j];
            else break;
        }
        
        return pre;
    }
};