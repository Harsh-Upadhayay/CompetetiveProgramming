class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0, num = x;
        
        while(x) 
            rev = rev * 10 + x % 10,
            x /= 10;
        
        return num == rev && num >= 0;
    }
};