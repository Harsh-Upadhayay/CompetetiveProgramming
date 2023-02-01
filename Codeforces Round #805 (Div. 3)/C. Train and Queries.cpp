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

ll ANS = 0;

ll countSubs(vll a, vll b) {

    ll sc = 0, ans = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] == b[i]) sc++;
        else {

            ans += ((sc * (sc + 1)) / 2);
            sc = 0;
        }
    }
    if(sc)
        ans += ((sc * (sc + 1)) / 2);

    return ans;
}

void combinationUtil(vll &arr, vll &data,
                    ll start, ll end,
                    ll index, ll r, vll &va, vll &vb){
    if (index == r)
    {   
        unordered_set<ll> comb;
        rpt(j, 0, r)
            comb.insert(data[j]);

        vll ta = va;

        rpt(i, 0, va.size())
            if(comb.count(ta[i]))
                ta[i] = vb[i];

        ANS = max(ANS, countSubs(ta, vb));
        
        return;
    }
 
    for (ll i = start; i <= end &&
        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1,
                        end, index+1, r, va, vb);
    }
}
 
void fun(vll &arr, ll n, ll r, vll &va, vll &vb) {
    vll data(r);
 
    combinationUtil(arr, data, 0, n-1, 0, r, va, vb);
}
 
void solve(void){
    ll n, k; cin >> n >> k;
    ANS = 0;
    string a, b; cin >> a >> b;

    vll va(n), vb(n);
    set<ll> st;
    rpt(i, 0, n) {
        va[i] = a[i] - 'a',
        vb[i] = b[i] - 'a';

        if(va[i] != vb[i])
            st.insert(va[i]);
    }


    ll ans = 0;

    if(k >= st.size())
        cout << countSubs(vb, vb);
    else if(k == 0)
        cout << countSubs(va, vb);
    else {

        vll diff;
        for(ll x : st) diff.push_back(x);

        fun(diff, diff.size(), k, va, vb);

        cout << ANS;

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
    