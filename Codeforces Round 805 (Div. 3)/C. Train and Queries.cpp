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

void modDfs(map<ll, vll> &adj, set<ll> &vis, ll src, ll dst) {

    vis.insert(src);
    if(src == dst)
        return;

    for(ll nd : adj[src])
        if(!vis.count(nd))
            modDfs(adj, vis, nd, dst);

}

bool isFlower(map<ll, vll> &adj, map<ll, ll> &degree, set<ll> vis) {

    ll v = vis.size();
    double clen = sqrt(v);

    if(float(clen) != ceil(clen))
        return false;

    vll freq(5, 0);
    vll corners;
    for(ll nd : vis) {
        if(degree[nd] == 2)
            freq[2]++;
        else if(degree[nd] == 4)
            freq[4]++,
            corners.push_back(nd);
        else
            return false;
    }

    for(ll crn : corners) {

        set<ll> vis;

        for(ll nd : adj[crn])
            if(degree[nd] == 2) {
                modDfs(adj, vis, nd, crn);
                break;
            }

        if(vis.size() != clen)
            return false;
    }

    return (freq[4] == clen || freq[2] == (clen * (clen - 1)));
}

void dfs(map<ll, vll> &adj, set<ll> &vis, set<ll> &compVis, ll src) {

    vis.insert(src);
    compVis.insert(src);

    for(ll x : adj[src])
        if(!vis.count(x)) 
            dfs(adj, vis, compVis, x);
        
}

void solve(void){
    
    ll v, e; cin >> v >> e;

    map<ll, ll> degree;
    map<ll, vll> adj;

    rpt(i, 0, e) {
        ll u, t; cin >> u >> t;
        degree[u]++;
        degree[t]++;
        adj[u].push_back(t),
        adj[t].push_back(u);
    }

    set<ll> vis, compVis;
    bool ans = true;

    ll comp = 0;
    rpt(i, 1, v + 1) {

        if(!vis.count(i)) {
            dfs(adj, vis, compVis, i); 
            ans &= isFlower(adj, degree, compVis);
            compVis.clear();
            comp ++;
        }
        if(comp > 1)
            kill("NO");
    }


    if(ans)
        yes
    else
        no
    // rpt(i, 1, v + 1)
    //     cout << i << " " << degree[i] << "\n";

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
