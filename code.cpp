        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans;

    cin >> n >> k;
    ll v[(n)];
    multiset<ll> s;

    rpt(n){
        cin >> v[i];
        s.insert(v[i]);
    }
    ll idx = 0;
    for(auto x : s)
        v[n - idx++ -1] = x;

    rpt(n){
        multiset<ll>::iterator itr = s.find(v[i]);
        if(itr == s.end())
            continue;
        cout << *itr << "\n";
        
    }

    for(auto x : v)
        cout << x << " ";
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
