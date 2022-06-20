        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool isPallindrom(ll n){
    ll rev = 0, _n = n;
    while(_n){
        rev += _n%10;
        _n /= 10;
    }
    return rev == n;
}

void solve(void){
    ll n, m, ans;
    cin >> n;
    ll len = log10(n), start = pow(10, len), end = 9.99999*start;
    // for(int i = pow(10, len); i < 9.99999*pow(10, len); i++)
    //     if(isPallindrom(n+i)){
    //         cout << i;
    //         break;
    //     }
    cout << len;
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


