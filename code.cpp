        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, maxDiff = INT_MIN;
    vector<ll> a(n), b(n);
    cin >> n;
    rpt(n)
        cin >> a[i];

    rpt(n){
        cin >> b[i];
        maxDiff = max(maxDiff, (a[i] - b[i]));
    }
    // cout << maxDiff;
    bool flag = true;

    cout << maxDiff;
    rpt(n){
        a[i] = ((a[i] > maxDiff)?(a[i]-maxDiff):0);
        if(a[i] != b[i])
            flag = false;
    }
    rpt(n)
        cout << a[i] << " ";
    cout << ((flag)?"YES":"NO");
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


