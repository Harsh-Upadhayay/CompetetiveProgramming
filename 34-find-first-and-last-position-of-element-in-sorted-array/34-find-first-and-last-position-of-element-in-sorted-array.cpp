class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> v(2, -1);
        
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + (r - l) / 2.0);
            if (nums[mid] == target) {
                if(mid - 1 < 0) {v[0] = mid; break;}
                else if(nums[mid - 1] != target) {v[0] = mid; break;}
                else r = mid - 1;    
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
        }
        
        l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + (r - l) / 2.0);
            if (nums[mid] == target) {
                if(mid + 1 >= nums.size()) {v[1] = mid; break;}
                else if(nums[mid + 1] != target) {v[1] = mid; break;}
                else l = mid + 1;    
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
        }
        
        return v;
    }
};