        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, r, c, ans;
    cin >> n >> m >> r >> c;
    vector<string> grid(n);
    rpt(n)
        cin >> grid[i];
    bool f = false
    ;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 'B')
                if(i+1 == r || j+1 == c)
                    f = true;
                
    if(grid[r-1][c-1] == 'B')
        ans = 0;
    if(f)
        ans = 1;
    else
        ans = 2;
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


