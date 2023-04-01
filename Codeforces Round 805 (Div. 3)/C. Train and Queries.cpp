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

ll dsum(ll n) {
    ll ans = 0;
    while(n)
        ans += n % 10,
        n /= 10;
    return ans;
}

ll bruteForce(ll l, ll r) {

    ll ans = 0;
    rpt(i, l, r + 1)
        ans += dsum(i);

    return ans;
}

pair<ll, ll> fun(string &ls, string &rs, ll i, ll upTight, ll loTight) {

    if(i = 0)
        return {1, 0};

    ll ub = upTight ? rs[rs.size() - i] - '0' : 9,
        lb = loTight ? ls[ls.size() - i] - '0' : 0,
        ansSum = 0, ansFreq = 0;
    debug(lb, ub, rs[rs.size()]);
    rpt(i, 0, 10) {

        if(i >= lb && i <= ub) {

            auto retV = fun(ls, rs, i - 1, upTight && (i == ub), loTight && (i == lb));
            ll sum = retV.second,
                freq = retV.first;

            ansSum += (i * freq + sum),
            ansFreq += freq; 

        }

    }
    return {ansFreq, ansSum};
}

optimized(ll l, ll r) {

    string ls = to_string(l),
            rs = to_string(r);

    ll lz = rs.size() - ls.size(),
        n = rs.size();

    reverse(all(ls));
    while(lz--)
        ls += '0';
    reverse(all(ls));

    cout << fun(ls, rs, n, 1, 1).second;

    return 0;
}

void solve(void){
    
    ll l, r; cin >> l >> r;

    cout << optimized(l, r);

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
