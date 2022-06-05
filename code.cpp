        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

void solve(void){
    ll n, x;
    cin >> n >> x;
    bool flag = false;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++){
        if(i == x)
            flag = true;
        i = i + v[i];
    }
    cout << (flag?"YES":"NO");
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


