#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)
#define rpt(i, s, e) for(ll (i) = (s); i < (e); i++)
#define vin(v, s, n) for(ll i = s; i < (n); i++) cin >> (v[i]);
#define vout(v, s, n) for(ll i = s; i < (n); i++) cout << (v[i]) << " ";
#define vec vector<ll>
#define nl cout << "\n";

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k;
    cin >> n >> k;
    vec v(n);
    vin(v, 0, n);
    if(n <= k){
        ll xtra = k - n;
        ll sum = accumulate(v.begin(), v.end(), 0) + xtra*n + (n*(n-1))/2;
        cout << sum;
    }
    else{
        ll sum = accumulate(v.begin(), v.begin() + k, 0), ans = sum;
        rpt(j, k, n){
            sum += v[j] - v[j-k];
            ans = max(ans, sum);
        }
        ans += (n*(n-1))/2;
        cout << ans;
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


