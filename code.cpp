        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool stop(unordered_map<ll, ll> m){
    for(auto x : m)
        if(x.first != x.second)
            return false;
    return true;
}

vector<vector<ll>> store;

void precompute(vector<ll> v){
    ll n = v.size();
    unordered_map<ll, ll> m;
    for(auto x : v)
        m[x]++;

    int i = 0;
    while(!stop(m)){
        for(auto &x : v)
            x = m[x];
        m.clear();
        for(auto x : v)
            m[x]++;
        store.pb(v);
    }
}

void solve(void){
    ll n, q;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];

    precompute(v);    

    cin >> q;
    rpt(q){
        ll x, k;
        cin >> x >> k;
    }
    for(auto x : store){
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
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


