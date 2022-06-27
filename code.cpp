        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll maxDist(ll i, ll j, ll n, ll m){
    ll x = max(i + j    , n - i + j);
    ll y = max(i + m - j, n - i + m - j);
    return max(x, y);
}

void solve(void){
    ll n, m, ans;
    cin >> n >> m;
    vector<ll> dist;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            // if(maxDist(i, j, n-1, m-1) == 6)
            //     cout << (n-1) << (m-1);
            dist.pb(maxDist(i, j, n-1, m-1));
        }
    sort(dist.begin(), dist.end());
    for(auto x : dist)
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


