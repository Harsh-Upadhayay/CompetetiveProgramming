        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans, o_min = INT_MAX, e_min = INT_MAX;
    cin >> n;
    ll v[n];
    rpt(n){
        cin >> v[i];
        if((i%2 == 0))
            e_min = min(e_min , v[i]);
        else
            o_min = min(o_min, v[i]);
    }
    cout << o_min << " " << e_min;
    if(n%2)
        cout << "Mike";
    else
        if(o_min == e_min)
            cout << "Joe";
        else
        cout << ((o_min > e_min) ? "Joe" : "Mike");
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


