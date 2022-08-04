class Solution {
public:
    
    int bsearch(vector<int> &v, int l, int r, int x) {
        if(l > r)       return -1;
        
        int mid = l + (r - l) / 2;
        if(v[mid] == x) return mid;
        if(v[mid] > x)  return bsearch(v, l, mid - 1, x);
        else            return bsearch(v, mid + 1, r, x);
    }
    
    int rbsearch(vector<int> &v, int l, int r, int x) {
        
        if(l > r)         return -1;
        if(l == r) {
            if(v[l] == x) return l;
            else          return -1;
        }
        
        int mid = l + (r - l) / 2;
        if(v[mid] == x) return mid;
        
        if(v[r] > v[mid]) {
            int idx = bsearch(v, mid + 1, r, x);
            if(-1 != idx) return idx;
            return rbsearch(v, l, mid - 1, x);
        } 
        else {
            int idx = bsearch(v, l, mid - 1, x);
            if(-1 != idx) return idx;
            return rbsearch(v, mid + 1, r, x);
        } 
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return rbsearch(nums, 0, nums.size() - 1, target);
    }
};