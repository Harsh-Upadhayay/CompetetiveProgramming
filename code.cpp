        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n;
    cin >> n;
    bool avilable[n+1] = {true};
    ll  ar[n+1];
    ar[n] = n;
    for(int i = n-1; i >= 0; i--){
        if(ar[i] - i > 0){
            ar[i] = ar[i] - i;
        }
        else
            ar[i] = ar[i] + i;
    }
    rpt(n)
        cout << ar[i+1] << " ";
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


