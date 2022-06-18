        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans, o_max = INT_MAX, e_max = INT_MAX;
    cin >> n;
    ll v[n];
    rpt(n){
        cin >> v[i];
        if(i%2)
            e_max = min(e_max , v[i]);
        else
            o_max = min(o_max, v[i]);
    }
    if(n%2)
        cout << "Mike";
    else
        cout << ((o_max > e_max) ? "Mike" : "Joe");
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


