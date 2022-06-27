        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans, mn, mi = 0;
    string s;
    cin >> s;
    mn = s[0];
    cout << ('c' < 'b');
    for(int i = 1; i < s.size(); i++)
        if(mn < s[i]){
            mn = s[i];
            mi = i;
        }
    cout << s[mi] << " ";
    for(int i = 0; i < s.size(); i++)
        if(i != mi)
            cout << s[i];
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


