class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        while(n) bits += n & 1, n = n >> 1;
        return bits;
    }
};