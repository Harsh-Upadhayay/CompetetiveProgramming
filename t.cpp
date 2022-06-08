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
    ll ar[n];
    rpt(n)
        cin >> ar[i];
    bool flag = true;
    ll big = ar[0], small = ar[0];
    for(int i = 1; i < n; i++){
        if(ar[i] < big && ar[i] > small){
            flag = false;
            break;
        }
        if(ar[i] > big){
            big = ar[i];
        }
        else if(ar[i] < small)
            small = ar[i];
    }
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


