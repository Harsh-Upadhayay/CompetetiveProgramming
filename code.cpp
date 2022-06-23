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
    string s;
    cin >> s;
    ll bc = 0;
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B')
            bc++;
        if(bc > i-bc+1)
            flag = false;
    }

    cout << ((bc && flag)? "YES":"NO");
    
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


