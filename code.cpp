        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;



void solve(){
    ll n, ans = 0;
    cin >> n;
    ll ar[n];
    rpt(n){
        cin >> ar[i];
        ans = ans | ar[i];
    }
    bool ff = false, sf = false, zf = false;
    bool flag = false;
    rpt(n)
        if(ar[i]){
            if(!ff)
                ff = true;
            else if(zf)
                sf = true;
        }
        else
            zf = true;
    if(!ans)
        cout << "0";
    else
        cout << (sf ? "2" : "1");

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


