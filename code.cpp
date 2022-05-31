        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n;
    cin >> n;
    vector<ll> v(n), ans(n, 0);
    unordered_map<ll, vector<ll>> m;
    unordered_map<ll, ll> freq;

    rpt(n){
        cin >> v[i];
    }

    for(auto x : v)
        freq[x]++;
    
    for(auto x : freq)
        if(x.second > 1){
            cout << "-1" << "\n";
            return;
        }    

    rpt(n){
        if(!m.count(v[i])){
            vector<ll> v;
            v.pb(i);
            m[v[i]] = v;
        }
        else
            m[v[i]].pb(i);
    }


    for(auto x : m){
        cout << x.first << " : ";
        for(auto y : x.second)
            cout << y << " ";
        cout << endl;
    }    

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


