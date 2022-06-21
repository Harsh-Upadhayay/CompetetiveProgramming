        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void pb(vector<vector<ll>> v){
    for(auto x : v){
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}

void solve(void){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> board(n, vector<ll> (m)), lsum(n, vector<ll> (m, 0)), rsum(n, vector<ll> (m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int j = 0; j < m; j++){
        
        for(int i = 0; i+j < n; i++)
            rsum[0][j] += board[i][i+j];

        for(int i = 0; i <= j; i++)
            lsum[0][j] += board[i][j-i]; 
    }

    for(int i = 1; i < n; i++){

        for(int j = 0; j+i < n; j++)
            rsum[i][0] += board[j+i][j];

        for(int j = m-1; j-i >= 0; j--)
            lsum[i][m-1] += board[i+m-1-j][j];
    }

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++){
            rsum[i][j] = rsum[i-1][j-1];
            lsum[i][j-1] = lsum[i-1][j];
        }
    
    // for(int i = 1; i < n; i++)
    //     for(int j = 1; j < m; j++)
    //         rsum[i][j] = rsum[i-1][j-1];
        

    pb(lsum);
    cout << "\n";
    pb(rsum);
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


