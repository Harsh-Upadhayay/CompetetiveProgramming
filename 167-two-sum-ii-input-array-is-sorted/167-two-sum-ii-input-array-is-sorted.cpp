class Solution {
public:
    
    int isPresent(vector<int> &v, int x) {
        int l= 0, r = v.size() - 1;
        while(l <= r) {
            int mid = r + (l - r) / 2;
            if(v[mid] == x) return mid;
            else if(v[mid] > x) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans, &v = numbers;
        
        for(int i = 0; i < numbers.size(); i++) {
            if(isPresent(numbers, target - v[i]) != -1 && isPresent(numbers, target - v[i]) != i) {
                ans.push_back(i + 1), ans.push_back(isPresent(numbers, target - v[i]) + 1); break;
            }
        }
        if(!ans.size())
            ans.push_back(-1), ans.push_back(0);
        sort(ans.begin(), ans.end());
        return ans;   
    }
};