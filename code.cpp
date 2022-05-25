#include<iostream>
#include<math.h>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

#define count(x) (ceil(log10(x)))

ll getMaxDigit(ll x){
    ll ans = 0;
    x = abs(x);
    while(x){
        ans = max(ans, x%10);
        x = x/10;
    }
    return ans;
}

void solve(void){
    ll n, x, ans = 0;
    cin >> n >> x;
    while(count(x) < n){
        ans++;
        pair<ll, ll> target(INT_MIN, 0);
        ll temp = x;
        while(temp){
            ll digit =  temp%10;
            temp = temp/10;
            ll thisProduct = digit * x;
            if(count(target.second) < count(thisProduct)
             || (count(target.second) == count(thisProduct) 
                && getMaxDigit(thisProduct) > target.first)){
                target.first = getMaxDigit(thisProduct);
                target.second = thisProduct;
            } 

        }

        x = target.second;
    }
    cout << ans << " ";
    cout << "\n";

}

int main() {
    // srand(time(0));

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



