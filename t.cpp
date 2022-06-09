        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans = INT_MIN, len = 0;
    map<ll, ll> m;
    cin >> n >> k;
    ll r = n-1;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    for(auto x : v)
        m[x]++;
    
    for(auto x : v)
        if(m[x] < k)
            m.erase(x);

    rpt(n)
        if(m[v[i]])
            len++;
        else{
            ans = max(ans, len);
            r = i;
            len = 0;
        }
    ans = (ans == INT_MIN ? n : ans);
    if(!ans)
        cout << "-1";
    else
        cout << (r-ans) << " " << r;
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


