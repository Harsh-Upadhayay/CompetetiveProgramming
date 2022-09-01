class Solution {
public:
    bool isPowerOfTwo(long long x) {
        return x && !(x & (x - 1)) ;
    }
};