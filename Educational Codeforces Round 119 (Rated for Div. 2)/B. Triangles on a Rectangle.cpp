/* https://codeforces.com/problemset/problem/1620/B */
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

double inline dist(pair<ll, ll> p1, pair<ll, ll> p2){
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;
    return sqrt((x2 - x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

double inline area(double a, double b, double c){
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) + s * (s - b) + s * (s - c));
}

// double calc(vector<ll> top){

// }

void solve(void){
    ll w, h; cin >> w >> h;

    vll tmp = {0, h};
    vector<vector<p(ll, ll)>> v(2);
    double mxArea = 0;

    rpt(i, 0, 2){
        ll k, x; cin >> k;
        
        while(k--){
            cin >> x;
            v[i].pb({x, tmp[i]});
        }

    }

    rpt(i, 0, 2){
        auto p = v[i].front(), q = v[i].back();
        auto &top = v[(i+1)%2];

        for(auto x : top){
            double a = dist(p, q),
                   b = dist(p, x),
                   c = dist(q, x);
            double ar = area(a, b, c);
            mxArea = max(mxArea, ar);
        }
    }

    tmp = {0, w};
    v[0].clear();
    v[1].clear();

    rpt(i, 0, 2){
        ll k, y; cin >> k;

        while(k--){
            cin >> y;
            v[i].pb({tmp[i], y});
            cout << y << " ";
        }

    }

    rpt(i, 0, 2){
        auto p = v[i].front(), q = v[i].back();
        auto &top = v[(i+1)%2];

        for(auto x : top){
            double a = dist(p, q),
                   b = dist(p, x),
                   c = dist(q, x);
            double ar = area(a, b, c);
            mxArea = max(mxArea, ar);
        }
    }

    cout << mxArea;

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