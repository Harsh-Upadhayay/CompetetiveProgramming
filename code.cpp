#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
    #define debug(x...) 
#else
    #include "debug.h"
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
#define TESTCASE

/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d = ninf, T e = ninf);
template<class T>
T inline min(T a, T b, T c, T d = inf, T e = inf);
template<class T>
void inline print(vector<T> v);
template<class T>
void inline print(vector<vector<T>> v);

/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/
ll block;
 
struct Query
{
    ll L, R, X;
};
 
bool compare(Query x, Query y)
{
    if (x.L / block != y.L / block)
        return x.L / block < y.L / block;
 
    return x.R < y.R;
}
 
void queryResults(ll a[], ll n, Query q[], ll m)
{
    block = (ll)sqrt(n);
 
    sort(q, q + m, compare);
 
    ll currL = 0, currR = 0;
 
    map<ll, ll> mp;
 
    for (ll i = 0; i < m; i++) {
         
        ll L = q[i].L, R = q[i].R, X = q[i].X;
 
        while (currL < L)
        {
            mp[a[currL]]--;
            currL++;
        }
 
        while (currL > L)
        {
            mp[a[currL - 1]]++;
            currL--;
        }
        while (currR <= R)
        {
            mp[a[currR]]++;
            currR++;
        }
 
        while (currR > R + 1)
        {
            mp[a[currR - 1]]--;
            currR--;
        }
 
        if (mp[X] != 0)
            cout << X << " exists between [" << L
                 << ", " << R << "] " << endl;
        else
            cout << X << " does not exist between ["
                 << L << ", " << R << "] " << endl;
    }
}
 
/**
 * int a[] = { 1, 1, 5, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = { { 0, 2, 2 }, { 1, 4, 1 }, { 2, 4, 5 } };
    int m = sizeof(q) / sizeof(q[0]);
    queryResults(a, n, q, m);
 */
void solve(void){
    ll n, q; cin >> n >> q;
    map<ll, list<ll>> mp;
    vll v(n);
    rpt(i, 0, n) {
        cin >> v[i];
        // debug(mp);
        mp[v[i]].pb(i);
    }
    debug(mp);
    rpt(i, 0, q){
        ll a, b;
        cin >> a >> b;

    }
    

    nl;
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    srand(time(0));

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
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
    nl;
}

template<class T>
void inline print(vector<vector<T>> v){
    for(auto x : v){
        for(auto y : x)
            cout << y << " ";
        nl;
    }
}

/*_________________________________________________________________________________________________________________________________________*/