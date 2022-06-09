        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans = INT_MIN;
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

    if(m.size() == 0){
        cout << "-1\n";
        return;
    }

    vector<ll> a;
    for(auto x : m)
        a.pb(x.first);

    ll prev, len = 0, _len = INT_MIN, r = a[a.size()-1], _r = INT_MIN;

    prev = a[0];
    for(ll i = 1; i < a.size(); i++){
        if(a[i] - prev == 1)
            len++;
        else{
            if(len > _len){
                _len = len;
                _r = r;
            }
            len = 0; 
        }
        r = prev = a[i];
    }
    if(len > _len){
        _len = len;
        _r = r;
    }
    
    cout << _len;
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


