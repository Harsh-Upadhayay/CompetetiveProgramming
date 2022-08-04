class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(auto x : s)
            if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')) a += tolower(x);
        for(int i = 0; i < a.size()/ 2; i++)
            if(a[i] != a[a.size() - i - 1])
                return false;
        return true;
        
    }
};