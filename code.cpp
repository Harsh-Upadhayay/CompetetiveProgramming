        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool allA(string s){
    for(auto x : s)
        if(x == 'B')
            return false;
    return true;
}

void solve(void){
    ll n, m, ans = 0;
    string s;
    cin >> s;
    bool flag = true;
    
    if(s.size() == 1)
        flag = false;

    for(int i = 0; i < s.size() - 1; i++)
        if(s[i] == 'B' && s[i+1] == 'B')
            flag = false;


    cout << (flag && !(allA(s))? "YES":"NO");
    
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


