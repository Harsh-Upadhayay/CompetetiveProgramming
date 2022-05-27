        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n,  ans, root;
    cin >> n;
    unordered_map<ll, vector<ll>> m;
    rpt(n){
        ll x; 
        cin >> x;
        if(x == i){
            root = x;
            continue;
        }
        auto tmp = m.find(x);
        if(tmp != m.end())
            (*tmp).second.pb(i+1);
        else{
            vector<ll> v;
            v.pb(i+1);
            m[x] = v;
        }
    }
    for(auto x : m){
        cout << x.first << " : ";
        for(auto y : x.second)
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


