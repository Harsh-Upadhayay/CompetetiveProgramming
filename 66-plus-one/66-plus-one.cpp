class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 0;
        
        digits[digits.size() - 1] += 1,
        carry = digits[digits.size() - 1] / 10,
        digits[digits.size() - 1] %= 10;
        
        for(int i = digits.size() - 2 ; i >= 0; i--) 
            digits[i] += carry,
            carry = digits[i] / 10,
            digits[i] %= 10;
    
        if(carry) {
            vector<int> v;
            v.push_back(carry);
            for(auto x : digits)
                v.push_back(x);
            return v;
        }
        return digits;
    }
};