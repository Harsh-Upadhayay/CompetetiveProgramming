class Solution {
    
    bool f(int n, int trn) {
        if(n == 1) return trn;
        
        bool stat = 0; 
        for(int i = 1; i < n; i++) {
            if(!(n % i))
                stat |= f(n - i, !trn);
        }
        
        return stat;
    }
    
public:
    bool divisorGame(int n) {
        return !(n % 2);    
    }
};