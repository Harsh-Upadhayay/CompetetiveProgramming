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

bool fun(pair<ll,ll> a, pair<ll, ll> b) {




}

void solve(void){
    ll n, c; cin >> n >> c;
    vll cst(n + 1, inf); rpt(i, 1, n + 1) cin >> cst[i];
    
    vll lfcst(n + 1, inf), rcst(n + 1, inf);

    rpt(i, 1, n + 1){

        lfcst[i] = cst[i] + i,
        rcst[i] = cst[i] + n - i + 1; 

    } 
    
    debug(lfcst);
    debug(rcst);

    bool firstItr = true;;
    multiset<pair<ll, ll>> lmp, rmp;

    for(int i = 1; i <= n; i++) 
        lmp.insert({lfcst[i], rcst[i]}),
        rmp.insert({rcst[i], lfcst[i]});

    ll ans = 0;
 
    while(c > 0) {

        auto lpath = lmp.begin(),
             rpath = rmp.begin();

        ll lcost = lpath -> first,
            rcost = rpath -> first;

        debug(lcost, rcost);
        if(firstItr) {

            firstItr = false;
            ans += (lcost <= c);
            c -= lcost;

            lmp.erase(lpath);
            rmp.erase({lpath -> second, lpath -> first});
            continue;
        }

        ans += (min(lcost, rcost) <= c);
        c -= min(lcost, rcost);

        if(lcost < rcost) {
            rmp.erase({lpath -> second, lpath -> first});
            lmp.erase(lpath);
        }
        else if(lcost > rcost) {
            lmp.erase({rpath -> second, rpath -> first});
            rmp.erase(rpath);
        }
        else {
            if(lpath -> second == rpath -> second) {
                lmp.erase({rpath -> second, rpath -> first});
                rmp.erase(rpath);

            }
            else if(lpath -> second > rpath -> second)  {
                rmp.erase({lpath -> second, lpath -> first});
                lmp.erase(lpath);
            }
            else{
                lmp.erase({rpath -> second, rpath -> first});
                rmp.erase(rpath);
            }
        }
    }

    debug(lmp);
    debug(rmp);
 
 
    cout << ans;
 
    debug('\n');
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
