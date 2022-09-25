class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s(jewels.begin(), jewels.end());
        char c = 0;
        for(char x : stones)
            c += s.count(x);
        return c;
    }
};