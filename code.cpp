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
    bool flag;
    vector<ll> v(n);
    rpt(n){
        cin >> v[i];
        flag = v[i] % 2;
    }
    if(flag){
        rpt(n){
            v[i] = v[i] % 3;
            v[i] = v[i] % 2;
        }
    }
    else{
        cout << "YES\n";
        return;
    }
    for(int i = 1; i < n; i++)
        if(v[i] != v[0]){
            cout << "NO\n";
            return;
        }
    cout << "YeES";
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


