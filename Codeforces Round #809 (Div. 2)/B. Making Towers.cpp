/* https://codeforces.com/contest/1706/problem/B */
#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
    #define debug(x...) 
    class Timer{};
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


const int MAXN = 100100;
 
int t, n;
ll a[MAXN];
 
ll get(int i) {
  return max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
}
 


ll stress(vll input){
 
    ll n = input.size();

    for (int i = 1; i <= n; i++)
      a[i] = input[i-1];
 
    if (n & 1) {
 
      ll ans = 0;
      for (int i = 2; i < n; i += 2)
        ans += get(i);
 
      return ans;
 
    }
 
    ll tot = 0;
    for (int i = 2; i < n; i += 2)
      tot += get(i);
 
    ll ans = tot;
    for (int i = n - 1; i > 1; i -= 2) {
      tot -= get(i - 1);
      tot += get(i);
      ans = min(ans, tot);
    }
 
    return ans;
 
  }

ll solve(vll input){
    ll n;  n = input.size();
    vll v(all(input));
 
    ll ans = 0;
    if(n % 2){
        for(ll i = 1; i < n - 1; i += 2){
            if(v[i] <= v[i-1] || v[i] <= v[i+1])
                ans += (max(v[i-1], v[i+1]) - v[i]) + 1;
        }
    }
    else{
        vll front, back;
        ll a1 = 0, a2 = 0;
 
        
        for(ll i = 1; i < n - 2; i += 2){
            if(v[i] <= v[i-1] || v[i] <= v[i+1])
                a1 += (max(v[i-1], v[i+1]) - v[i]) + 1;
            front.pb(a1);
        }
 
        
        for(ll i = n - 2; i >= 2; i -= 2){
            if(v[i] <= v[i-1] || v[i] <= v[i+1])
                a2 += (max(v[i-1], v[i+1]) - v[i]) + 1;
            back.pb(a2);
        }
        reverse(all(back));
 
        for(ll i = 0; i < n / 2 -1; i++)
            if(front[i] < back[i])
                ans = front[i];
            else{
                if(i - 1 >= 0)
                    ans = front[i-1] + back[i];
                else ans = back[i];
                break;
            }
 
        // debug(front, back);
        front.clear();
        back.clear();
        reverse(all(v));
        a1 = 0; a2 = 0;
        ll ans2 = 0;
  
        for(ll i = 1; i < n - 2; i += 2){
            if(v[i] <= v[i-1] || v[i] <= v[i+1])
                a1 += (max(v[i-1], v[i+1]) - v[i]) + 1;
            front.pb(a1);
        }
 
        
        for(ll i = n - 2; i >= 2; i -= 2){
            if(v[i] <= v[i-1] || v[i] <= v[i+1])
                a2 += (max(v[i-1], v[i+1]) - v[i]) + 1;
            back.pb(a2);
        }
        reverse(all(back));
 
        for(ll i = 0; i < n / 2 -1; i++)
            if(front[i] < back[i])
                ans2 = front[i];
            else{
                if(i - 1 >= 0)
                    ans2 = front[i-1] + back[i];
                else ans2 = back[i];
                break;
            }
 
        // debug(front, back);
        // debug(a1, a2);
        ans = min(ans, ans2, front.back(), back.front());
    }
    return ans;
}
 


void init(){
    ll n = rand() % 20 + 3;
    vll v(n); rpt(i, 0, n) v[i] = rand() % 10;

    ll a = stress(v);
    ll b = solve(v);

    // debug(a, b, v);
    if(a != b){
        debug(a, b, v);
        exit(0);
    }
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    srand(time(0));
    #ifndef ONLINE_JUDGE
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
        init();

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
