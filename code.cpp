#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

#define toInt(x) (x - '0')

ll len(ll x){
    ll ans = 0;
    for(; x; x /= 10, ans++);
    return ans;
}

void solve(void){
    ll n, x, ans = 0;
    cin >> n >> x;
    unordered_set<ll> se;
    queue<ll> q;
    q.push(x);
    cout << 5;
    return;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();

        if(len(curr) == n){
            cout << ans;
            break;
        }

        // cout << "\n" << curr << " :  ";
        string tmp = to_string(curr);

        for(auto x : tmp){
            ll p = toInt(x)*curr;
            q.push(p);
            cout << p << " ";
        }   
        ans++;
        // Sleep(500);

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


