#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
    #define debug(x...) 
#else
    #include "debug.h"
#endif

/*-----------------------------------------------------------------------------------------------------------------------------*/

#define ll                      long long int
#define ull                     unsigned ll
#define ld                      long double
#define p(x, y)                 pair<x, y> 
#define pb                      push_back
#define fi                      first
#define se                      second
#define lb                      lower_bound
#define ub                      upper_bound
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

/*-----------------------------------------------------------------------------------------------------------------------------*/

template<class T>
T inline max(T a, T b, T c, T d = ninf, T e = ninf);
template<class T>
T inline min(T a, T b, T c, T d = inf, T e = inf);
template<class T>
void inline print(vector<T> v);
template<class T>
void inline print(vector<vector<T>> v);

/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------*/

bool inline potentialP(ll i, vector<string> &t){
    return (t[0][i] == t[1][i] && t[0][i+1] == t[1][i+1]) && t[0][i] != t[0][i+1];
}

void mark(ll i, vector<string> &t){
    t[0][i] = t[1][i] = t[0][i+1] = t[1][i+1] = '-';
}

void solve(void){
    ll n; cin >> n;
    vector<string> t(2); rpt(i, 0, 2) cin >> t[i];
    string s = "";
    // debug(t);

    ll ans = 0;
    for(int i = 0; i < n-1; i++)
        if(potentialP(i, t)){
            mark(i, t), ans += 2, i++;
        }

    rpt(i, 0, n)
        if(t[0][i] != t[1][i])
            ans += 2;
        else if(t[0][i] == '0')
            ans += 1;
    debug(t);
    cout << ans;
    debug(s);
    nl;
}


/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------*/


    

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

/*-----------------------------------------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------------------------------------*/