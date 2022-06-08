        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans = INT_MIN, len = 1;
    map<ll, ll> m;
    cin >> n >> k;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    for(auto x : v)
        m[x]++;
    
    for(auto x : v)
        if(m[x] < k)
            m.erase(x);

    for(auto x : v)
        if(m[x])
            len++;
        else{
            ans = max(ans, len);
            len = 1;
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


