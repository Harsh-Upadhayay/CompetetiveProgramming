        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll find(vector<ll> v, ll x){
    ll r = v.size()-1, l = 0, res = -1;
    while(l <= r){
        ll mid = r - (r-l)/2;
        if(v[mid] < x)
            l = mid + 1;
        else if(v[mid] > x)
            r = mid-1;
        else{
            res = mid;
            r = mid-1;
        }
    }
    return res;
}

void solve(void){
    ll n, k, ans;
    cin >> n >> k;
    vector<ll> v(n), psum(n, 0);
    rpt(n)
        cin >> v[i];
    psum[0] = v[0];
    rpt(n-1)
        psum[i+1] += psum[i] + v[i+1];
    ll l = -1, r = -1, _l = 0, mxLen = INT_MIN;
    rpt(n){
        ll len;
        if(psum[i] == k)
            len = i+1;
        
        else if(psum[i] > k){
            _l = find(psum, psum[i]-k);
            // cout << _l << " ";
            len = i - _l;
        }

        if(len > mxLen){
            mxLen = len;
            r = i;
            l = _l;
        }
    }
    cout << l + (n-r+1);
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


