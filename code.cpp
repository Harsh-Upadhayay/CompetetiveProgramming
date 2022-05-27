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
    string s;
    unordered_map<ll, vector<ll>> m;
    rpt(n){
        ll x;
        cin >> x;
        auto t = m.find(x);
        if(t != m.end()){
            (*t).second.push_back(i+2);
        }
        else{
            vector<ll> v;
            v.push_back(i+2);
            m[x] = (v);
        }
    }
    cin >> s;
    for(auto x : m){
        cout << x.first << " : ";
        for(auto y : x.second)
            cout << y << " ";
        cout << "\n";
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


