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

class tester{
    public : 
    vector<vector<int>> perms;
    int __size;
    int __a[100];

    tester(int siz, vector<ll> v){
        __size = siz;
        for(int i = 0; i < __size; i++)
            __a[i] = i;

        heapPermutation(__a, __size, __size);
    }

    void heapPermutation(int a[], int size, int n)
    {
        if (size == 1) {
            vector<int> perm;
            rpt(i, 0, n)
                perm.pb(a[i]);
            perms.pb(perm);
            return;
        }
     
        for (int i = 0; i < size; i++) {
            heapPermutation(a, size - 1, n);
     
            if (size % 2 == 1)
                swap(a[0], a[size - 1]);
     
            else
                swap(a[i], a[size - 1]);
        }
    }

    

};

void solve(void){
    // ll n, ans; cin >> n;
    // vector<ll> v(n); rpt(i, 0, n) cin >> v[i];

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