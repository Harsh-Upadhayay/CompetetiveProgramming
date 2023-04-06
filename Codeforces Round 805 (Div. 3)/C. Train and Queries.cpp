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

ll smallerCount(ll n) {

    string num = to_string(n);
    ll sz = num.size();

    vector<ll> prev(2, 1), curr(2, 1);

    for(int n = 1; n <= sz; n++, prev = curr) 
        for(int tight = 1; tight >= 0; tight--) {
            ll ub = tight ? num[sz - n] - '0' : 9,
            ans = 0;
            rpt(i, 0, ub + 1) 
                if(i != 4)
                    ans += prev[tight && (i == ub)];


            curr[tight] = ans;
        }
    return curr[1] - 1;
}


ll rem4(ll mid) {

    string str = to_string(mid);
    ll ans = 0;
    bool four = false;
    for(char x : str)
        if(four) {
            ans = ans * 10 + 9;
        }
        else
        {
            if(x == '4')
                ans = (ans * 10) + (x - 1 - '0'),
                four = true;
            else
                ans = (ans * 10) + (x - '0');
        }

    return ans;
}

ll optimized(ll n) {

    ll l = 1, r = 1e13; 

    while(l < r) {
        // debug(l, r);
        ll mid = r - ((r - l) / 2),
            midCnt = smallerCount(mid);

        if(midCnt < n) 
            l =  mid + 1;
        else if(midCnt > n)
            r = mid - 1;
        else {
            return (rem4(mid));
        }

    }

    return min(rem4(l), rem4(r));
}


void solve(void){

    // ll n; cin >> n;

    // cout << optimized(n);

    rpt(i, 1, 1e4) {
        // Timer _;
        // debug(i);
        optimized(1e12);
    }
    
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
