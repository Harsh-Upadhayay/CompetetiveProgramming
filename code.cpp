        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans, mx = INT_MIN, m_i, m_j;
    cin >> n >> m;
    vector<vector<ll>> grid;
    for(int i = 0; i < n; i++){
        vector<ll> v;
        for(int j = 0; j < m; j++){
            ll x;
            cin >> x;
            if(mx < x){
                m_i = i;
                m_j = j;
                mx = x;
            } 
            v.pb(x);
        }
        grid.pb(v);
    }
    ll a_i = INT_MIN, a_j = INT_MIN;

    a_i = min(n - m_i, m_i + 1);
    a_j = min(m - m_j, m_j + 1);
    cout << a_i << " " << a_j;
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


