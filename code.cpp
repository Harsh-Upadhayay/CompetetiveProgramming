        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool chk(ll *ar, ll n){
    rpt(n-1)
        if(abs(ar[i] - ar[i+1]) % (i+1))
            return false;
    return true;
}

void solve(void){
    ll n;
    cin >> n;
   vector<bool> avilable(n, true);
    ll  ar[n];
    ar[n-1] = n;
    for(int i = n-2; i >= 0; i--){
        if(ar[i+1] - i-1 > 0){
            ar[i] = ar[i+1] - i-1;

        }
        else{
            ar[i] = ar[i+1] + i + 1;
        }
    }
    rpt(n)
        avilable[ar[i]] = false;
    for(int i = 1; i <= n; i++)
        if(avilable[i]){
            ar[0] = i;
            break;
        }
        rpt(n)
            cout << ar[i] << " ";
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


