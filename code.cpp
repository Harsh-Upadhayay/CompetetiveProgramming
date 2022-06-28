        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, k;
    string ans;
    cin >> n;
    vector<ll> a(n);
    rpt(n)
        cin >> a[i];
    vector<ll> v;
    for(auto x : a)
        if(x)
            v.pb(x);

    if(v.size() > 2)
        ans = "NO";
    else if(v.size() < 2)
        ans = "YES";
    else{
        if(v[0] == ((-1)*v[1]))
            ans = "YES";
        else 
            ans = "NO";
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


