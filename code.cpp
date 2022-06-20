        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;



void solve(void){
    ll len, num, m, ans;
    string s;
    cin >> s;
    bool flag = true;
    // if(s.size() == 1){
    //     if(s[0] <= 'z' && s[0] >= 'a')
    //         cout << s;
    //     else

    //         cout << tolower(s[0]);
    //     cout << "\n";
    //     return;
    // }
    for(int i = 1; i < s.size(); i++){
        if(s[i] <= 'z' && s[i] >= 'a')
            flag = false;
    }
    int start;
    if(flag){
        if(s[0] <= 'z' && s[0] >= 'a')
            start = 1;
        else
            start = 0;

        if(start)
            s[0] = toupper(s[0]);
        for(int i = start; i < s.size(); i++)
            s[i] = tolower(s[i]);

    }
    cout << s;
    // cout << start << " " << end;
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


