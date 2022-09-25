class Solution {
public:
    string toLowerCase(string s) {
        for (char &x : s) x = tolower(x);
        return s;
    }
};