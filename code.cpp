        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans;

    cin >> n >> k;
    vector<ll> v(n);
    multimap<ll, ll> m;

    rpt(n){
        cin >> v[i];
        m.insert(make_pair(v[i], i));
    }
    int i = 0;
    for(auto x : m)
        v[i++] = x.first;
    for(auto x : v)
        cout << x << " ";
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


