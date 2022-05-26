#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;


void solve(void){
    ll n, m, ans;
    cin  >> n >> m;
    ll ar[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> ar[i][j];
    
    ll r = -1;

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++) 
            if(ar[i][j-1] > ar[i][j]){
                r = i;
                break;
            }
        if(r != -1)
            break;
    }
    if(r == -1)
        cout << "1 1";
    else{
        ll temp[m], a = -1, b = -1;
        bool flag = true;
        for(int i = 0; i < m; i++)
            temp[i] = ar[r][i];
        sort(temp, temp+m);
        for(int i = 0; i < m; i++){
            if(ar[r][i] != temp[i])
                if(-1 == a)
                    a = i;
                else if(-1 == b)
                    b = i;
                else{
                    cout << temp[a] << temp[b] << temp[i];
                    cout << "-1";
                    flag = false;
                    break;
                }
        }
        // cout << a << " " << b;
        if(flag){
            // cout << "S";
            for(int i = 0; i < n; i++){
                swap(ar[i][a], ar[i][b]);
            }

    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < m; j++) 
    //         cout << ar[i][j] << " ";
             for(int i = 0; i < n; i++){
                for(int j = 1; j < m; j++) 
                    if(ar[i][j-1] > ar[i][j]){
                        cout << "-1";
                        flag = false;
                        break;
                    }
                if(!flag)
                    break;
            }
            if(flag)
                cout << (a+1) << " " << (b+1);
        }
    }
    cout<<endl;
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


