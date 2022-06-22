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
    ans = !(n%2);
    rpt((n-1)/2){
        // ans += (2 * !((n-i-1) % (i+1)) );
        if(!((n-i-1) % (i+1)))
            cout << n-i-1 << " : " << i+1 << "\n";
        // ll x = __gcd(i+1, n-i-1);
        // ans = x + (((i+1) * (n-i-1))/x);
        // cout << i+1 << " " << n-i-1 << " : " << ans << "\n";
    }

    // cout << ans;
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


