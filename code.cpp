        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, maxDiff = INT_MIN;
    cin >> n;
    ll a[n], b[n];
    
    rpt(n)
        cin >> a[i];

    rpt(n)
        cin >> b[i];
        
    rpt(n){
        ll t = (a[i] - b[i]);
        maxDiff = max(maxDiff, t);
    }

    if(maxDiff < 0){
        cout << "NO\n";
        return;
    }

    if(maxDiff == 0){
        bool inflag = true;
        
        rpt(n)
            if(a[i] != b[i])
                inflag = false;

        if(inflag)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    rpt(n)
        if(a[i] > maxDiff)
            a[i] = a[i] - maxDiff;
        else
            a[i] = 0;

    bool flag = true;

    rpt(n)
        if(a[i] != b[i])
            flag = false;

    if(flag)
        cout << "YES";
    else
        cout << "NO";

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



