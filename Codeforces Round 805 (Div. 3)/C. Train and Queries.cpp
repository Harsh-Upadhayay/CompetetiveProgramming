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
#define TESTCASE
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

/**
 * fi = len,
 * se = cnt
**/

pair<ll, ll> groups(vll &v, ll totK, vector<vector<vector<pair<ll, ll>>>> &dp, ll ind, ll k, ll prevIdx) {

    // debug(ind, k, prevE);
    if(ind == v.size()) {
        return {0, 0};
    }

    if(dp[ind][k][prevIdx + 1].fi != -1 && dp[ind][k][prevIdx + 1].se != -1)
        return dp[ind][k][prevIdx + 1];

    ll take = 0, nottake = 0;

    ll tcnt = 0, ntcnt = 0;

    if(prevIdx == -1 || v[prevIdx] == v[ind]) {
        auto it = groups(v, totK, dp, ind + 1, (k + 1) % totK, ((!((k + 1) % totK)) ? -1 : ind) );
        ll gp = it.fi, cnt = it.se;
        take = !((k + 1) % totK) + gp;
        tcnt = cnt;
    }

    auto it = groups(v, totK, dp, ind + 1, k, prevIdx);
    ll gp = it.fi, cnt = it.se;

    nottake = gp;
    ntcnt = cnt;

    if(ntcnt == 0 && nottake != 0) ntcnt = 1;
    if(tcnt == 0 && take != 0) tcnt = 1;

    if(take < nottake) {

        return dp[ind][k][prevIdx + 1] = {nottake, ntcnt};

    }
    else if(take > nottake) {

        return dp[ind][k][prevIdx + 1] = {take, tcnt};

    }
    else {

        return dp[ind][k][prevIdx + 1] = {take, ntcnt + tcnt};

    }
    return dp[ind][k][prevIdx + 1] = {max(take, nottake), cnt};
}

void solve(void){
    
    ll n, k; cin >> n >> k; 
    vll v(n); rpt(i, 0, n) cin >> v[i];

    vector<vector<vector<pair<ll, ll>>>> dp(n, 
            vector<vector<pair<ll, ll>>> (k,
                vector<pair<ll, ll>>(n, {-1, -1})));

    ll maxLen = groups(v, k, dp, 0, 0, -1).se;
    debug(maxLen);



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
