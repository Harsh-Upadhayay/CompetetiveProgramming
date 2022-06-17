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
    ll freq[10] = {0};
    rpt(n){
        ll x;
        cin >> x;
        freq[x%10]++;
    }
    rpt(10)
        cout << freq[i] << " ";
    vector<int> v;
    for(int j = 0; j < 10; j++){
        ll itrs = min(freq[j], 3ll);
        rpt(itrs)
            v.pb(j);
    }
    rpt(v.size())
        cout << v[i] << " ";
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++)
                if((v[i]+v[j]+v[k]) % 3 == 0)
                    flag = true;
    }
    cout << (flag ? "YES":"NO");
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


