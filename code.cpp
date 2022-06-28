        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, k, sum = 0;
    string ans;
    cin >> n;
    bool flag = false;
    vector<ll> a(n);
    rpt(n){
        cin >> a[i];
        sum += a[i];
     }
    vector<ll> v;
    for(auto x : a){
        if(x == sum)
            flag = true;
        if(x)
            v.pb(x);
    }

    if(v.size() > 2)
        ans = "NO";
    else if(v.size() < 2)
        ans = "YES";
    else{
        if(v[0] == ((-1)*v[1]))
            ans = "YES";
        else 
            ans = "NO";
    }
    if(n == 3 && flag)
        ans = "YES";
    flag = true;
    if(n == 4 && v.size() == 4) {
        for(auto x : a)
            if(sum - x != x)
                flag = false;
        if(flag)
            ans = "YES";
    }
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
