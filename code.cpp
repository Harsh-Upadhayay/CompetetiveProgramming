        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans, x, y;
    string s;
    rpt(8){
        cin >> s;
        int j = 1, idx = -1;
        bool flag = true;
        for(auto x : s){
            ++j;
            if(x == '#' && idx == -1)
                idx = j;
            else{
                flag = false;
                continue;
            }
        }
        if(flag){
            x = i+1;
            y = idx;
        }

    }
    cout << x << " " << y;
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


