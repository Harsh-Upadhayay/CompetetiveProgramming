/*  *//*  */
#include<bits/stdc++.h>
using namespace std;

#ifdef DarkLord
    #include "debug.h"
#else
    #define debug(x...) 
    class Timer{};
#endif

/*_________________________________________________________________________________________________________________________________________*/

#define ll                      long long int
#define ull                     unsigned ll
#define ld                      long double
#define p(x, y)                 pair<x, y> 
#define pb                      push_back
#define fi                      first
#define se                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define vll                     vector<ll>
#define vvll                    vector<vector<ll>>
#define ninf                    ((ll)((-1)*1e18+5))
#define inf                     ((ll)(1e18+5))
#define MOD                     ((ll)(1e9+7))
#define nmin(v)                 *min_element(all(v))
#define nmax(v)                 *max_element(all(v))
#define rpt(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x)                  (x).begin(), (x).end() 
#define yes                     cout << "YES";
#define no                      cout << "NO";
#define nl                      cout << "\n";
#define kill(x)                 {cout << x << "\n"; return; }
#define SIEVE_SIZE                ((ll)(1e5))
/*_________________________________________________________________________________________________________________________________________*/

template <typename T>
ostream& operator<<(ostream &os, vector<T> &v) {
    for(T x : v) os << x << " ";
    return os;
}

template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for(T &x : v) is >> x;
    return is;
}

template <typename T1, typename T2>
ostream& operator<<(ostream &os, pair<T1, T2> &x) {
    cout << "(" << x.fi << "," << x.se << ")";
    return os;
}

template <typename T>
istream& operator>>(istream &is, vector<vector<T>> &v) {
    for(auto &x : v) is >> x;
    return is;
}

template <typename T>
ostream& operator<<(ostream &os, vector<vector<T>> &v) {
    for(auto x : v) os << x << "\n";
    return os;
}


bitset<SIEVE_SIZE> isComposit;
void setSieve();

set<ll> allPrimes;
void storePrimes();
/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/
class Solution {

    int fun(vector<int> v, vector<vector<int>> &dp, int i, int j) {
        
        if(i == j)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];

        int n = v.size(),
        optAns = 0, totSum = 0, curSum = 0;

        for(int k = i; k <= j; k++)
            totSum += v[k];

        for(int k = i; k < j; k++) {

            curSum += v[k];

            if(curSum < (totSum - curSum))
                optAns = max(optAns, curSum + fun(v, dp, i, k));
            
            else if(curSum > (totSum - curSum))
                optAns = max(optAns, (totSum - curSum) + fun(v, dp, k + 1, j));

            else
                optAns = max({optAns, curSum + fun(v, dp, i, k), (totSum - curSum) + fun(v, dp, k + 1, j)});
        }
        
        return dp[i][j] = optAns;
    }

public:
    int stoneGameV(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {

                int optAns = 0, totSum = 0, curSum = 0;

                for(int k = i; k <= j; k++)
                    totSum += v[k];

                for(int k = i; k < j; k++) {

                    curSum += v[k];

                    if(curSum < (totSum - curSum))
                        optAns = max(optAns, curSum + dp[i][k]);
                    
                    else if(curSum > (totSum - curSum))
                        optAns = max(optAns, (totSum - curSum) + dp[k + 1][j]);

                    else
                        optAns = max({optAns, curSum + dp[i][k], (totSum - curSum) + dp[k + 1][j]});
                }
                
                dp[i][j] = optAns;

            }
        }

        return fun(v, dp, 0, n - 1);
    }
};
void init(){

    return;
}


#define TESTCASE
void solve(ll __T__){

    ll n; cin >>  n;
    vector<int> v(n); cin >> v;

    auto obj = Solution();
    cout << obj.stoneGameV(v);

    nl;
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    srand(time(0));
    #ifdef DarkLord
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    init();

    ll t = 1;

    #ifdef TESTCASE
        cin >> t;
    #endif

    rpt(i, 1, t + 1) 
        solve(i);

    return 0;
}

/*_________________________________________________________________________________________________________________________________________*/

void setSieve(){
    isComposit[0] = isComposit[1] = 1;
    for(long long i = 2; i*i <= SIEVE_SIZE; i++)
        if(isComposit[i] == 0)
            for(long long j = i*i; j <= SIEVE_SIZE; j += i)
                isComposit[j] = 1;

}

void storePrimes(){
    if(isComposit[2])
        setSieve();
    for(ll i = 2; i < SIEVE_SIZE; i++)
        if(!isComposit[i])
            allPrimes.insert(i);
}

/*_________________________________________________________________________________________________________________________________________*/

