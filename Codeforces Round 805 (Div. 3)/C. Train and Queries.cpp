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

template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    rpt(i, 0, v.size()) is >> v[i];
    return is;
}

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

ll fun(vll &s, vll &c,vector<vector<vector<ll>>> &dp, ll i, ll j, ll k) {
    
    if(k == 0)
        return 0;

    if(dp[i][j + 1][k] != -1)
        return dp[i][j + 1][k];

    if(i >= s.size())
        return inf;

    ll take = inf, nottake = inf;

    nottake = fun(s, c, dp, i + 1, j, k);

    if(j == -1 || s[i] > s[j])
        take = c[i] + fun(s, c, dp, i + 1, i, k - 1);

    return dp[i][j + 1][k] = min(take, nottake);
}

void solve(void){
    
    ll n; cin >> n;
    vll s(n), c(n); cin >> s >> c;


    vector<vector<ll>> next(n + 1, vector<ll>(4, 0)), curr(next);

    for(int j = 0; j <= n; j++)
        for(int k = 0; k <= 3; k++)
            next[j][k] = inf;
    

    for(int j = 0; j <= n; j++)
        next[j][0] = curr[j][0] = 0;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 2; j >= -1; j--) {
            for(int k = 3; k > 0; k--) {


                ll take = inf, nottake = inf;

                nottake = next[j + 1][k];

                if(j == -1 || s[i] > s[j])
                    take = c[i] + next[i + 1][k - 1];

                curr[j + 1][k] = min(take, nottake);

            }
        }
        next = curr;
    }

    ll ans = curr[0][3];
    cout << (ans == inf ? -1 : ans);
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
