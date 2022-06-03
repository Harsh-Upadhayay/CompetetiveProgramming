        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k;
    cin >> n;
    ll ans_max = 0, ans_min = 0;
    ans_max = n/4;
    ans_min = n/6;
    if(!ans_max || !((n%4) && (n%6)) )
        cout << "-1";
    else if(!ans_min)
        cout << ans_max << " " << ans_max;
    else
        cout << ans_min << " " << ans_max;
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


