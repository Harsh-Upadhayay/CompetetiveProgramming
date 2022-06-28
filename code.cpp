        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, q,ans;
    set<ll> candies;
    cin >> n >> q;
    ll prev = 0;
    vector<ll> v;
    rpt(n){
        ll x;
        cin >> x;
        v.pb(x);
    }
    vector<ll> preSum;
    preSum.pb(v[0]);
    rpt(n-1)
        preSum.pb(preSum[i]+v[i+1]);
    rpt(n)
        cout << preSum[i];
    rpt(q){
        ll qry;
        cin >> qry;
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


