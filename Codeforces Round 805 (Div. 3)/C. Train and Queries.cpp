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

bool isBoring(ll n) {
    vll v;
    while(n)
        v.push_back(n % 10),
        n /= 10;
    reverse(all(v));

    rpt(i, 0, v.size())
        if((i + 1) % 2 != (v[i] % 2))
            return false;
    return true;
}

ll bruteForce(ll l, ll r) {

    ll ans = 0;
    rpt(i, l, r + 1) 
        if(isBoring(i)){
            // cout << i << "\n";
            ans++;
        }

    return ans;
}

ll fun(string &l, string &s, vector<vector<vector<vector<vector<ll>>>>> &dp, ll dig, bool odd, bool leadz, bool tight, bool loTight) {

    if(dig == 0) 
        return !leadz;
 
    if(dp[dig][odd][leadz][tight][loTight] != -1)
        return dp[dig][odd][leadz][tight][loTight];

    ll ans = 0,
        ub = tight ? s[s.size() - dig] - '0' : 9,
        lb = loTight ? l[l.size() - dig] - '0' : 0;

    if(!odd) {

        vll avil = {0, 2, 4, 6, 8};

        for(ll i : avil)
            if(i >= lb && i <= ub) 
                ans += fun(l, s, dp, dig - 1, 1, 0, (tight && (i == ub)), (loTight && (i == lb)));

    }
    else {

        vll avil = {1, 3, 5, 7, 9};

        if(leadz && lb == 0)
            ans += fun(l, s, dp, dig - 1, 1, 1, 0, 1);

        for(ll i : avil)
            if(i >= lb && i <= ub)
                ans += fun(l, s, dp, dig - 1, 0, 0, (tight && (i == ub)), (loTight && (i == lb)));

    }

    return dp[dig][odd][leadz][tight][loTight] = ans;
}

ll optimized(ll l, ll r){



    string ls = to_string(l),
            rs = to_string(r);

    ll diff = rs.size() - ls.size();
    reverse(all(ls));
    while(diff--)
        ls += '0';
    reverse(all(ls));

    vector<vector<vector<vector<vector<ll>>>>> dp(
        rs.size() + 1, vector<vector<vector<vector<ll>>>> (
            2, vector<vector<vector<ll>>>(
                2, vector<vector<ll>> (
                    2, vector<ll> (
                        2, -1)))));

    bool odd = 1, leadz = 1, tight = 1, loTight = 1;
    // ll lft = fun(ls, dp, ls.size(), odd, leadz, tight);
    // rpt(i, 0, rs.size() + 1)
    //     rpt(j, 0, 2) rpt(k, 0, 2) rpt(l, 0, 2) rpt(m, 0, 2) dp[i][j][k][l][m] = -1;
    // debug(dp);
    ll rt = fun(ls, rs, dp, rs.size(), odd, leadz, tight, loTight);
    
    return  rt;
}

void solve(void) {

    // ll lim = 10000;
    // ll l = 1 + (rand() % lim);
    // ll r = l + (rand() % lim);


    // if(bruteForce(l, r) != optimized(l, r)) {
    //     debug(l, r, bruteForce(l, r), optimized(l, r));
    //     return;
    // }

    ll l, r; cin >> l >> r;
    cout << optimized(l, r);
    nl;
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    // srand(time(0));
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

    rpt(i, 1, t + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }

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
