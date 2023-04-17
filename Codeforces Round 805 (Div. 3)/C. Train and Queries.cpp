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

void init(){

    return;
}

ll fun(vll &w, vll &v, vvll &dp, ll i, ll val)  {
    debug(i, val);
    if(val == 0)
        return 0;

    if(i == v.size())
        return inf;

    if(dp[i][val] != -1)
        return dp[i][val];

    ll take = inf, nottake inf;

    nottake = fun(w, v, dp, i + 1, val);

    if(v[i] <= val)
        take = w[i] + fun(w, v, dp, i + 1, val - v[i]);

    return dp[i][val] = min(take, nottake);
}



// #define TESTCASE
void solve(ll __T__){

    ll n, c; cin >> n >> c;
    vll v(n), w(n);

    rpt(i, 0, n)
        cin >> w[i] >> v[i];


    ll mxVal = 0; rpt(i, 0, n) mxVal += v[i];

    vvll dp(n + 1, vll(mxVal + 1, -1));

    while(mxVal) {
        cout << mxVal;
        if(fun(w, v, dp, 0, mxVal) < c)
            kill(mxVal);
        mxVal -= 1;
    }

    cout << 0;

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

