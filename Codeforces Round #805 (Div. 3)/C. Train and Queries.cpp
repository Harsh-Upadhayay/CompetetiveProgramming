#include<bits/stdc++.h>
using namespace std;

#define MOD ((long long)1000000007)

long long f(vector<vector<long long>> &grid, vector<vector<long long>> &dp, int i, int j) {
    cout << i << " " << j << "\n";
    if(i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    // diag

    long long diag = 0;
    for(int itr_i = i - 1; itr_i >= 0 && j - (i - itr_i) >= 0; itr_i --)
        diag = grid[itr_i][j - itr_i] * (diag % MOD + f(grid, dp, itr_i, j - (i - itr_i)) % MOD) % MOD;

    // up
    long long up = 0;
    for(int itr_j = j - 1; itr_j >= 0; itr_j--)
        up  = grid[i][itr_j] * (up % MOD + f(grid, dp, i, itr_j) % MOD) % MOD;

    // left
    long long left = 0;
    for(int itr_i = i - 1; itr_i >= 0; itr_i--)
        left  = grid[itr_i][j] * (left % MOD + f(grid, dp, itr_i, j) % MOD) % MOD;

    // cout << up << " " << left << " " << diag << "\n";

    return dp[i][j] = (up + left + diag);
}

void solve(void){
    
    long long n, m; cin >> n >> m;
    vector<vector<long long>> grid(n, vector<long long> (m, 0));
    vector<vector<long long>> dp(n, vector<long long> (m, -1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << f(grid, dp, n - 1, m - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}