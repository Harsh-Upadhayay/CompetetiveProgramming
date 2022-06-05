        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans = INT_MIN, _a, _b;
    cin>>n;
    ll f, a = 1, b = n-1;
  
    if(n == 2){
        a = 1;
        b = 1;
    }
    else
        if(n%2){
            a = (n/2);
            b = ((n/2) + 1);
        }
        else
            if(!(n%4)){
                a = ((n/2) -1);
                b = ((n/2) + 1);
            }
            else{
                a = ((n/2) - 2);
                b = ((n/2) + 2);
            }
    f = ( ((a*b)/__gcd(a, b)) - __gcd(a, b));
    cout << f;    
    // rpt(n/2){
    //     f = ( ((a*b)/__gcd(a, b)) - __gcd(a, b));
    //     if(ans < f){
    //         _a = a;
    //         _b = b;
    //         ans = f;
    //     }
    //     a++;
    //     b--;
    // }
    // cout << _a << " " << _b << " : " << ans;
    cout << "\n";

}

int main() {
    srand(time(0));

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        cout << "\n";

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


