        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll fun(vector<ll> v, ll x){
    ll l = 0, r = v.size() - 1; 
    while(l <= r){
        ll mid = r - (r-l)/2;
        if(v[mid] > x)
            r = mid - 1;
        else if(v[mid] < x){
            if(mid + 1 < v.size())
                if(v[mid+1] > x)
                return mid;
            l = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}

void solve(void){
    ll n, x, ans = 0;
    cin >> n;
    vector<ll> v(n);
    
    rpt(n)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    vector<ll> preSum(n);
    preSum[0] = v[0];
    
    for(ll i = 1; i < n; i++)
        preSum[i] = preSum[i-1] + v[i];

    cout << fun(v, x);
    // while(1){
    //     ll f = fun(preSum, x);
    //     if(x != -1)
    //         ans += f+1;
    //     else
    //         break;
    //     x--;
    // }

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


