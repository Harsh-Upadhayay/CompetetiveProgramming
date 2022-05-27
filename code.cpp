        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, ans = INT_MIN, k;
    map<ll, ll> m;
    cin >> n >> k;

    rpt(n){
        ll x;
        cin >> x;
        m[x]++;
    }
    for(auto x : m)
        if(x.second < k)
            m.erase(x.first);

    ll r = -1, l = -1, prev = -1;
    vector<ll> v;
    for(auto x : m)
        v.pb(x.first);

    ll curr = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] - v[i-1] == 1){
            curr++;
        }
        else{
            if(curr > ans){
                l = v[i-curr];
                ans = curr;
            }
            curr = 1;
        }
    }

    if(v.size())
        cout << l << " " << (l + curr);
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


