class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 0;
        int siz = digits.size();
        digits[siz - 1] += 1,
        carry = digits[siz - 1] / 10,
        digits[siz - 1] %= 10;
        
        for(int i = siz - 2 ; i >= 0; i--) 
            digits[i] += carry,
            carry = digits[i] / 10,
            digits[i] %= 10;
    
        if(carry) {
            vector<int> v;
            v.push_back(carry);
            for(int x : digits)
                v.push_back(x);
            return v;
        }
        return digits;
    }
};