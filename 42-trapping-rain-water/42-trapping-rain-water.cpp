class Solution {
public:
    int trap(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
    int trapp(vector<int>& height) {
        int n = height.size();
        vector<int> hfroml(n, INT_MIN), hfromr(n, INT_MIN);

        hfroml[0] = height[0];
        hfromr[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++) 
            hfroml[i] = max(hfroml[i - 1], height[i]);
        for(int i = n - 2; i >= 0; i--)
            hfromr[i] = max(hfromr[i + 1], height[1]);
        
        for(auto x : height)
            cout << x << " ";
        cout << "\n";
        cout << "  ";
        int water = 0;
                
        for(int i = 1; i < n - i; i++) {
            // if(min(hfroml[i], hfromr[i]) > height[i])
                water += min(hfroml[i], hfromr[i]) - height[i];
                cout << water << " ";
        }
        cout << "\n";
        for(auto x : hfroml)
            cout << x << " ";
        cout << "\n";
        for(auto x : hfromr)
            cout << x << " ";
        return water;
    }
};