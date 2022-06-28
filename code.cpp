        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool isEqual(vector<ll> &v, ll start, ll end, ll x){
    while(start > 0 && start <= end)
        if(v[--start] != x)
            return false;
    return true;
}

void solve(void){
    ll n, m, ans = 0;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    ll len = 1;
    ll i = n-1;
    ll x = v[n-1];
    ll j = 10;
    while(i > 0){
        ll t = len;
        bool flag = true;
        if(!isEqual(v, i, n-len, x))
            ans++;
        i = n-len;
        len *= 2;
    }   
    // if(ans && n%2)
    //     ans -= (v[n/2] == x);
    cout << ans;
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


