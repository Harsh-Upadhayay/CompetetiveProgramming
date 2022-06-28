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
    ll x = v[0];
    rpt(n-1)
        x  = x ^ v[i+1];
    for(int i = 0; i < n; i++){
        ll tx = 0;
        for(int j = 0; j < n; j++){
            if(i != j)
                tx = tx ^ v[i];
        }
        if(tx == v[i]){
            cout << v[i] << "\n";
            return;
        }
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


