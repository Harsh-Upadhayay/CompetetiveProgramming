        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if(s[n-1] == '0'){
        for(ll i = n-2; i >=0; i--){
            if(s[i] == '1' && ((n-i-1) <= k)){
                ans -= 10;
                k -= (n-i-1);
                break;
            }
        }
    }
    // cout << " " << k << " ";
    if(s[0] == '0')
        for(ll i = 1; i < n-1; i++){
            if(s[i] == '1' && ((i) <= k)){
                ans -= 1;
                k -= (i);
                break;
            }
        }
    // cout << ans << " : ";

    for(ll i = 0; i < n-1; i++)

        if(s[i] == '1' && s[i+1] == '1')
            ans += 11;
        else if(s[i] == '1' && s[i+1] == '0')
            ans += 10;
        else if(s[i] == '0' && s[i+1] == '1')
            ans += 1;
        else if(s[i] == '0' && s[i+1] == '0')
            ans += 0;

    cout << ans;
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


