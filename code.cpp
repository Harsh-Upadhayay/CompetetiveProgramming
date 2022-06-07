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

    ll d[n] = {0}, s[n], f[n];

    rpt(n)
        cin >> s[i];

    rpt(n)
        cin >> f[i];

    d[0] = f[0] - s[0];

    for(int i = 1; i < n; i++){

        if(s[i] > f[i-1])
            d[i] = f[i] - s[i];
        else
            d[i] = f[i]- s[i-1];
    }

    rpt(n)
        cout << d[i] << " ";

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


