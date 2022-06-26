        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

vector<pair<ll, ll>> breakit(vector<ll> &v, ll m){
    
    vector<pair<ll, ll>> a;
    ll i = 0, j;
    ll n = v.size();
    while(i < n){
        ll x = 1, t = v[i];
        while(!(t%m)){
            x *= m;
            t /= m;
        }
        a.pb({t, x});
        i++;
    }

    i = 0;
    vector<pair<ll, ll>> flist; 
    while(i < n-1){
        ll f = a[i].second;
        while(i < n-1 && a[i].first == a[i+1].first){
            i++;
            f += a[i].second;
        }
        flist.pb({a[i].first, f});  
        i++;      
    }
    ll x = a.size();
    if(a[x-1].first != a[x-2].first){
        flist.pb({a[x-1].first, 1});
    }
    // for(auto x : a)
    //     cout << " (" << x.first << ", " << x.second << ") ";
    return flist;
}

bool isEqual(vector<pair<ll, ll>> a, vector<pair<ll, ll>> b){
    for(ll i = 0; i < a.size(); i++)
        if( a[i].first != b[i].first ||
            a[i].second != b[i].second)
            return false;
    return a.size() == b.size();
}

string Asolve(ll n, ll m, vector<ll> &a, ll k, vector<ll> &b) {
 
    // ll n, m;
    // cin >> n >> m;
    // vector<ll> a(n);
    vector<pair<ll, ll>> M, L;
    ll N = 0, y = 0;
    for (ll i = 0; i < n; i++) {
        // cin >> a[i];
        ll j = 1;
        while (a[i] % m == 0) {
            j *= m;
            a[i] /= m;
        }
        if (a[i] != N) {
            if (N != 0) {
                M.push_back({N, y});
            }
            N = a[i];
            y = j;
        } else {
            y += j;
        }
    }
    M.push_back({N, y});
    // ll k; cin >> k;
    // vector<ll> b(k);
    N = 0, y = 0;
    for (ll i = 0; i < k; i++) {
        // cin >> b[i];
        ll j = 1;
        while (b[i] % m == 0) {
            j *= m;
            b[i] /= m;
        }
        if (b[i] != N) {
            if (N != 0) {
                L.push_back({N, y});
            }
            N = b[i];
            y = j;
        } else {
            y += j;
        }
    }
    L.push_back({N, y});
    if (M != L) {return "NO";}
    return "YES";
 
}

string Hsolve(ll n, ll m, vector<ll> &v, ll k, vector<ll> &p){
    // ll n, m, ans, k;
    // cin >> n >> m;
    // vector<ll> v(n);
    // rpt(n)
    //     cin >> v[i];
    // cin >> k;
    // vector<ll> p(k);
    // rpt(k)
    //     cin >> p[i];
    
    vector<pair<ll, ll>> a, b;

    a = breakit(v, m);
    b = breakit(p, m);

    // for(auto x : b)
    //     cout << " (" << x.first << ", " << x.second << ") ";
    
    return (isEqual(a, b)?"YES":"NO");
}

void solve(){
    ll n, m, ans, k;
    // cin >> n >> m;
    ll _ = 0;
    while(_++ < 2){
        n = rand()% (ll)10e1;
        m = rand()% (ll)10e1 + 2;
        vector<ll> v(n);
        rpt(n)
            v[i] = rand()% (ll)10e1;
        k = rand()% (ll)10e1;
        vector<ll> p(k);
        rpt(k)
            p[i] = rand()% (ll)10e1;
        cout << n << " " << m << "\n";
        rpt(n)
            cout << v[i] << " ";
        cout << "\n";
        cout << k;
        // vector<ll> p(k);
        rpt(k)
            cout << p[i] << " ";
        
        // cout << solve(n, m, v, k, p);
        // if(Hsolve(n, m, v, k, p) != Asolve(n, m, v, k, p)){
        //     cout << n << " " << m << "\n";
        //     rpt(n)
        //         cout << v[i] << " ";
        //     cout << k;
        //     // vector<ll> p(k);
        //     rpt(k)
        //         cout << p[i] << " ";
        //     cout <<Hsolve(n, m, v, k, p) << " " << Asolve(n, m, v, k, p);
        //     break;
        // }
    }
}

int main() {
    // srand(time(0));

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    #ifdef TESTCASE
        cin>>t;
        T=t;
        #else
        t = 1;
    #endif

    while(t--) 
        solve();

    return 0;
}


