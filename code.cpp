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
    cout << n;
    while(_n){
        rev += _n % 10;
        _n /= 10;
    }
    cout << rev << " ";
    return rev == n;
}

void solve(void){
    ll len, num, m, ans;
    cin >> len >> num;
    ll  n = log10(num), start = ceil(pow(10, n)), end = (10*start)-1;
    start--;
    while(start++ != end)
        if(isPallindrom(12)){
            cout << start;
            break;
        }
    // cout << start << " " << end;
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


