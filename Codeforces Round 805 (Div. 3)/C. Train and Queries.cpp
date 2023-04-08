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


void solve(void){
    
    ll n; cin >> n; 
    vll cost(n);
    vector<string> vit(n);
    rpt(i, 0, n) {cin >> cost[i] >> vit[i]; sort(all(vit[i]));}

    debug(cost, vit);

    vector<vector<vector<vector<ll>>>> dp(n + 1, 
        vector<vector<vector<ll>>> (2, 
            vector<vector<ll>> (2, 
                vector<ll> (2, inf))));
    vector<vector<vector<ll>>> curr(2, 
            vector<vector<ll>> (2, 
                vector<ll> (2, inf))), prev(curr);
    dp[0][1][1][1] = 0;

    for(int i = 0; i < n; i++) {

        for(int a = 1; a >= 0; a--) {
            for(int b = 1; b >= 0; b--) {
                for(int c = 1; c >= 0; c--) {

                    ll take, nottake;

                    nottake = dp[i][a][b][c];
                    
                    ll curA = 0, curB = 0, curC = 0;
                    
                    for(auto x : vit[i])
                        curA |= (x == 'A'),
                        curB |= (x == 'B'),
                        curC |= (x == 'C');

                    take = cost[i] + dp[i][a | curA][b | curB][c | curC];

                    dp[i + 1][a][b][c] = min(take, nottake);
                }
            }
        }

    }

    ll ans = dp[n][0][0][0]; 
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
