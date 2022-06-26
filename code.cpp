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

void solve(void){
    ll n, m, ans, k;
    cin >> n >> m;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    cin >> k;
    vector<ll> p(k);
    rpt(k)
        cin >> p[i];
    
    vector<pair<ll, ll>> a, b;

    a = breakit(v, m);
    b = breakit(p, m);
    for(auto x : b)
        cout << " (" << x.first << ", " << x.second << ") ";
    
    cout << (isEqual(a, b)?"YES":"NO");
    cout<<endl;

}

int main() {
    srand(time(0));

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


