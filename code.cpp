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


    // cout << "G";
    vector<vector<int>> matrix;
    vector<int> fr(n, 1);
    matrix.push_back(fr);
    for(int i = 1; i < n; i++){
        vector<int> r(n, 0);
        r[0] = 1;
        matrix.push_back(r);
    }

    // cout << n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;  j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
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


