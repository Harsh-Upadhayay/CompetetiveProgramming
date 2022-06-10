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
    vector<ll> v(n), ans;
    rpt(n)
        cin >> v[i];
    set<ll> s(v.begin(), v.end());

    rpt(n){
        if(s.empty()){
            cout << "*";
            break;
        }
        // s.erase(v[i]);
        auto x = *s.begin();
        if(x == v[i])
            x = *(++s.begin());
        ans.pb(x);
        // s.insert(v[i]);
        s.erase(x);
    }
    rpt(n)
        cout << ans[i] << " ";
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


