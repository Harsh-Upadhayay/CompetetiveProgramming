        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

pair<ll, ll> fun(vector<ll> str)
{
    pair<ll, ll> ans;

    ll n = str.size();
 
    ll res = 0; // result
 
    // last index of all characters is initialized
    // as -1
    map<ll, ll> lastIndex; 
    // Initialize start of current window
    ll i = 0;
 
    // Move end of current window
    for (ll j = 0; j < n; j++) {
 
        // Find the last index of str[j]
        // Update i (starting index of current window)
        // as maximum of current value of i and last
        // index plus 1
        if(lastIndex.count(str[j]))
            // i = max(i, lastIndex[str[j]] + 1);
        
        // Update result if we get a larger window
        if(res < (j-i+1)){
            cout << i << " ";
            res = (j - i + 1);
            ans = make_pair(i, i+res-1);
        }
        
        // Update last index of j.
        lastIndex[str[j]] = j;
    }    
    return ans;
}
void solve(void){
    ll n, m, ans;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    auto x = fun(v);
    cout << x.first << " " << x.second;
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


