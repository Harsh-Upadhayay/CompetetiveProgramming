        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m;
    cin >> n;
    ll x, y;
    vector<ll> ans;
    bool flag = true;
    cin >> x;
    rpt(n-1){
        cin >> y;
        if(flag)
            flag = y == x;
    }
    if(flag){
        rpt(n)
            ans.pb(n-i);
        if(n%2)
            swap(ans[0], ans[n/2]);
        rpt(n)
            cout << ans[i] << " ";
    }
    else 
        cout << "-1";
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


