        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

// void solve(void){
//     unsigned ll n, m, ans;
//     cin >> n >> m;
//     unsigned ll mx = 0;
//     rpt(n){
//         unsigned ll x;
//         cin >> x;
//         mx = max(mx, x);
//     }
//     mx = mx | m;
//     cout << mx;
//     cout<<endl;

// }

void solve(){
    ll n, ans = 0;
    cin >> n;
    ll ar[n];
    rpt(n){
        cin >> ar[i];
        ans = ans | ar[i];
    }
    bool flag = false;
    rpt(n-2)
        if(ar[i] && !ar[i+1] && ar[i+2])
            flag = true;

    if(!ans)
        cout << "0";
    else
        cout << (flag ? "2" : "1");
    
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


