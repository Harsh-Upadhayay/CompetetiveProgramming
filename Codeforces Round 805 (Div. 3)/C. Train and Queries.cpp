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
     ll it = 0; for(T x : v) os << it++ << ": " << x << "\n";
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
    ll o, p, c;
    nd() {};
    nd(ll x) : o(x), p(x), c(x) {}
    nd(ll x, ll y, ll z) : o(x), p(y), c(z) {}
 };

 ostream& operator<<(ostream &os, nd &n) {
     os << n.o << "," << n.p << "," << n.c;
     return os;
 }
 
vector<nd> segT;


void build(string &s, ll ind, ll low, ll high) {
    // debug(ind, low, high);
    if(low == high) {
        segT[ind] = nd(s[low] == '(', 0, s[high] == ')');
        return;
    }

    ll mid = (low + high) / 2;

    build(s, 2 * ind + 1, low, mid);
    build(s, 2 * ind + 2, mid + 1, high);

    segT[ind].o = segT[2 * ind + 1].o + segT[2 * ind + 2].o;
    segT[ind].p = segT[2 * ind + 1].p + segT[2 * ind + 2].p;
    segT[ind].c = segT[2 * ind + 1].c + segT[2 * ind + 2].c;
    
    segT[ind].p += max(0ll, min(
                        segT[2 * ind + 1].o - segT[2 * ind + 1].p, 
                        segT[2 * ind + 2].c - segT[2 * ind + 2].p
                        ));

}

nd query(ll ind, ll low, ll high, ll qlow, ll qhigh) {

    // full
    if(qlow <= low && qhigh >= high) 
        return segT[ind];
    // none 
    if(qlow > high || qhigh < low)
        return nd(-1);
    // partial 

    ll mid = (low + high) / 2;

    nd lft = query(2 * ind + 1, low, mid, qlow, qhigh),
        rgt = query(2 * ind + 2, mid + 1, high, qlow, qhigh);

    
    if(lft.o == -1)
        return rgt;
    if(rgt.o == -1)
        return lft;

    nd retVal(lft.o + rgt.o, lft.p + rgt.p, lft.c + rgt.c);

    retVal.p += min(lft.o - lft.p, 
                    rgt.c - rgt.p
                    );

    return retVal;
}

 // #define TESTCASE
 void solve(ll __T__){
 
     string s; cin >> s;
     ll n = s.size();

     segT.resize(4 * n);
     build(s, 0, 0, n - 1);

     ll q; cin >> q;
     while(q--) { 

        ll l, r; cin >> l >> r;
        cout << (2 * query(0, 0, n - 1, l - 1, r - 1).p) << "\n";
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
 
 