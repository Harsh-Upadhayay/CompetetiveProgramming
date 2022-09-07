class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set dist(candyType.begin(), candyType.end());
        return dist.size() >= candyType.size() / 2 ? candyType.size() / 2 : dist.size();
    }
};