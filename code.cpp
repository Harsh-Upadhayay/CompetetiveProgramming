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
    ll s, f, ax, in;
    s = n % 6; 
    f = n % 4;
    if(s == 0){
        in = n / 6;
    }
    else if(s == 2  || s == 4){
        in = n / 6 + 1;
    }
    else
        in = -1;

    if(f == 0){
        ax = n / 4;
    }
    else
        ax = -1;

    if(in == -1 || ax == -1)
        cout << "-1";
    cout << in << ax;
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


