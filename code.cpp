        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans = 0;
    cin>>n;
    string en, gr;
    cin >> en >> gr;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(gr[i] == '1'){
            ans++;
            if(en[i] == '0')
                en[i] = '-';
            else if(i != 0 && en[i-1] == '1')
                en[i-1] = '-';
            else if(i != n-1 && en[i+1] == '1')
                en[i+1] = '-';
            else
                ans--;                
        }
    }
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


