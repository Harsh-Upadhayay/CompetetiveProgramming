/*  */
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
// #define TESTCASE
#define SIEVE_SIZE                ((ll)(1e5))
/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d = ninf, T e = ninf);
template<class T>
T inline min(T a, T b, T c, T d = inf, T e = inf);
template<class T>
void inline print(vector<T> v);
template<class T>
void inline print(vector<vector<T>> v);

bitset<SIEVE_SIZE> isComposit;
void setSieve();

set<ll> allPrimes;
void storePrimes();
/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

void init(){

    return;
}

ll fun(string &a, string &b,vector<vector<ll>> &dp, ll i, ll j) {

    if(dp[i + 1][j + 1] != -1) return dp[i + 1][j + 1];
    
    if(i == 0 && j == 0) return dp[1][1] = a[0] == b[0];
    if(i < 0 || j < 0) return dp[i + 1][j + 1] = max(i, j) + 1;


    if(a[i] == b[j]) return dp[i + 1][j + 1] = fun(a, b, dp, i - 1, j - 1);

    else
        return dp[i + 1][j + 1] = 1 + min({fun(a, b, dp, i - 1, j),
                        fun(a, b, dp, i, j - 1),
                        fun(a, b, dp, i - 1, j - 1) });

}

void solve(void){
    string a, b; cin >> a >> b;
    ll n = a.size(), m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, -1));

    vll curr(m + 1, -1), prev(m + 1, -1);
    for(int j = 0; j <= m; j++)
        prev[j] = j;


    for(int i = 0; i < n; i++) {
        // print(prev); nl;
        curr[0] = i + 1;
        for(int j = 0; j < m; j++) {

            if(i == 0 && j == 0) curr[1] = a[0] == b[0];
            else if(a[i] == b[j]) curr[j + 1] = prev[j];
            else
                curr[j + 1] = 1 + min({
                                prev[j + 1],
                                curr[j],
                                prev[j]
                                    }); 

        }
        prev = curr;
    }

    cout << curr[m] << fun(a, b, dp, n - 1, m - 1);
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

    while(t--) 
        solve();

    return 0;
}

/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d, T e){
    return max(max(max(a, b), max(c, d)), e);
}

template<class T>
T inline min(T a, T b, T c, T d, T e){
    return min(min(min(a, b), min(c, d)), e);
}

template<class T>
void inline print(vector<T> v){
    for(auto x : v)
        cout << x << " ";
}

template<class T>
void inline print(vector<vector<T>> v){
    for(auto x : v){
        for(auto y : x)
            cout << y << " ";
        nl;
    }
}

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
