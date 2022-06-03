        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans;
    cin >> n >> k;
    if(n == k-1){
        cout << "-1";
        return;
    }
    cout << "0 " << (n-k-1) << "\n";
    cout << (n-1) << " " << k << "\n";

    rpt(n/2){
        if(i == 0 || i == (n-k-1) || i == k)
            continue;
        cout << i << " " << (n-i-1) << "\n";
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


