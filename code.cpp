        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll mod = (10e9 + 7);

void solve(void){
    ll n, m, ans;
    cin>>n;
    ll v;
    rpt(n)
        cin >> v;
    rpt(n)
        cin >> v;
    rpt(n){
        cin >> v;
        if(!v)
            ans = (ans%mod * 2)%mod;
    }
    cout << ans;
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


