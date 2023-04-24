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
    for(T x : v) os << (x == inf ? "i" : to_string(x)) << " ";
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

struct nd {
    ll u, v, t;

    nd(ll _u, ll _v, ll _t) {
        u = _u;
        v = _v;
        t = _t;
    }
};

vll ans;

ll fun(vector<nd> adj[], ll dst, vvll &dp, ll src, ll places) {

    if(dp[src][places] != -1)
        return dp[src][places];    
    if(places == 0)
        return dp[src][places] = (src == dst ? 0 : inf);

    if(dp[src][places] != -1)
        return dp[src][places];

    ll minT = inf, minN = -1;

    for(auto adjN : adj[src]) {

        ll x = adjN.t + fun(adj, dst, dp, adjN.v, places - 1);

        if(x < minT)
            minT = x, 
            minN = adjN.v;

    }
    if(minN != -1)
        ans.push_back(minN);

    return dp[src][places] = minT;
}
ll cost;

ll minAdj(vector<nd> adj[], vvll &dp, ll i, ll j) {
    if(j < 0)
        return 0;
    ll n = -1, t = inf;

    for(auto adjN : adj[i]) {
        if(t >= dp[adjN.v][j]) 
            t = dp[adjN.v][j],
            n = adjN.v;
    }
    cost += t;
    debug(i, j, n, t, cost);
    return n;
}

// #define TESTCASE
void solve(ll __T__){
    cost = 0;
    ll n, m, tim; cin >> n >> m >> tim;
    vector<nd> adj[n + 1];

    rpt(i, 0, m) {
        ll u, v, t; cin >> u >> v >> t;
        adj[u].push_back(nd(u, v, t));
    }

    // rpt(i, 1, n + 1) {
    //     cout << i << ": ";
    //     for(auto x : adj[i])
    //         cout << x.v << "," << x.t << "   ";
    //     cout << "\n";
    // }

    /* fun(src, place) -> minimum time to visit place number of showplaces from source. */

    /* 
    rpt(place, 1, n + 1) {
        if(fun(1, place) <= tim)
            cout << place;
    }
    */

    vvll dp(n + 1, vll(n + 1, -1));

    ll tgt = -1;
    rpt(place, n + 1, 0) { 
        ans.clear();

        if(fun(adj, n, dp, 1, place) <= tim) { 
            tgt = place;
            cout << place + 1 << "\n1 ";
            reverse(all(ans));
            cout << ans;
            break;
        }
    }

    if(tgt == -1)
        return;

    for(auto &x : dp)
        for(auto &y : x)
            if(y == -1)
                y = inf;

    ll src = 1;
    while(tgt >= 0) {

        // cout << src << " ";        
        tgt -= 1;

        src = minAdj(adj, dp, src, tgt);
    } 
    // nl;
    // cout << dp;

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
//  123 153 
// 1 48 33 103 87 114 73 134 11 141    49 94     18 88 93 53 82 112 111 39 60 61 57 3 152 110 143 66 2 27 149 65 4 119 133 109 138 70 37 10 74 67 21 69 42 83 121 36 104 40 144 97 147 130 29 127 98 22 7 107 148 31 8 106 5 38 117 132 150 124 59 118 56 99 84 71 142 43 100 90 113 146 47 95 50 85 136 135 137 45 86 145 76 52 129 44 79 28 140 78 34 81 51 19 54 32 91 154 92 25 75 23 16 80 131 46 77 17 26 126 125 122 96 9 35 13 20 116 115 55 105 6 58 12 30 72 41 14 102 108 120 128 15 68 63 89 151 101 139 24 156 ...
// 1 48 33 103 87 114 73 153 11 141 64 62 94 155 18 88 93 53 82 112 111 39 60 61 57 3 152 110 143 66 2 27 149 65 4 119 133 109 138 70 37 10 74 67 21 69 42 83 121 36 104 40 144 97 147 130 29 127 98 22 7 107 148 31 8 106 5 38 117 132 150 124 59 118 56 99 84 71 142 43 100 90 113 146 47 95 50 85 136 135 137 45 86 145 76 52 129 44 79 28 140 78 34 81 51 19 54 32 91 154 92 25 75 23 16 80 131 46 77 17 26 126 125 122 96 9 35 13 20 116 115 55 105 6 58 12 30 72 41 14 102 108 120 128 15 68 63 89 151 101 139 24 156 
// ...
