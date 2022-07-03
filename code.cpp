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

string shit(ll n, ll k, vll vec){

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i].first = vec[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (v[i - 1].second + 1 != v[i].second)
            ans++;
    return (ans <= k ? "YES" : "NO") ;
}   


void solve(void){
    ll n, k; n = rand()%10 + 2, k = rand()%n + 1;
    vector<ll> v(n);
    set<ll> added;
    rpt(i, 0, n){
        ll x = rand() % 20;
        while(added.count(x))
            x = rand() % 20;
        v[i] = x;
        added.insert(x);
    } 
    set<ll> s(all(v));

    ll i = 0, x = 0;
    while(i < n){
        auto itr = s.find(v[i]);

        while(i < n && *itr == v[i]) 
            i++, itr++;
        x++; 
    }

    if(shit(n, k, v) != (x <= k ? "YES": "NO")){ 
        debug(n, k, v, shit(n, k, v));

        exit(0);
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