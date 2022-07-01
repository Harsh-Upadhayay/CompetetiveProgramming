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

vector<bool> isComposit = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1};

bool isPrime(string s){
    return (s == "23" || s == "53" || s == "37" || s == "73");
}

void solve(void){
    ll n; cin >> n;
    string s; cin >> s;

    vector<ll> freq(10, 0);

    for(auto x : s)
        freq[x-'0']++;

    ll ans = 0;
    rpt(i, 1, 10)
        if(isComposit[(i)] && freq[i] > 0)
            ans = i;
    if(ans){
        cout << "1\n" << ans << "\n"; return;
    }

    rpt(i, 1, 10)
        if(freq[i] > 1)
            ans = i;
    if(ans){
        cout << "2\n" << ans << ans, nl; return;
    }
    
    string num = "";
    num += s[0];

    cout << "2\n";
    rpt(i, 1, n)
        if(!isPrime(num+s[i]))
            cout << (num + s[i]);
        else
            num = "", num += s[0];

    
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