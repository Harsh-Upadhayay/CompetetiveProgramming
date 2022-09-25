class Solution {

    unordered_map<int, int> mem;

    public:
    int minDays(int n) {
        
        if(mem.find(n) == mem.end()){
            
            if(n <= 1) {mem[n] = n; return n;}
            
            int a, b, c;
            a = b = c = INT_MAX;
            
            b = n % 3 + minDays((n - n % 3) / 3);
            c = n % 2 + minDays((n - n % 2) / 2);
            
            
            mem[n] = min({a, b, c}) + 1;
        }
        
        return mem[n];
    }
};
