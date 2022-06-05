#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    vector<ll> t(v.begin(), v.end());
    sort(t.begin(), t.end());
    vector<pair<ll, ll>> idx;
    ll start = 0, end = -1;
    rpt(n){
        if(t[i] != v[i])
            end++;
        else{
            if(start <= end)
                idx.pb(make_pair(start, end));
            start = i + 1;
            end = i;
        }
    }
    if(start <= end)
        idx.pb(make_pair(start, end));

    cout << idx.size() << "\n";

    for(auto x : idx){
        
        cout << x.first << " " << x.second << endl;
    }

    cout << "\n";

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


