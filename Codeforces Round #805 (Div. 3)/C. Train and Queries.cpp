

/*_________________________________________________________________________________________________________________________________________*/

//            _|      _|    _|_|_|_|_|    _|              _|_|         _|    _|
//            _|_|    _|        _|        _|            _|    _|        _|  _|
//            _| _|   _|        _|        _|           _|      _|        _|_|
//            _|  _|  _|        _|        _|           _|_|_|_|_|         _|
//            _|   _| _|        _|        _|           _|      _|         _|
//            _|    _|_|        _|        _|           _|      _|         _|
//            _|      _|    _|_|_|_|_|    _|_|_|_|_|   _|      _|         _|
   
                   /* Code by :-  Nilay Patel (nilay__patel) */

#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i = (a); i <= (b); i++)
#define fr(i,a,b) for(ll i = (a); i >= (b); i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define F first
#define S second
#define vi vector<ll>
#define inf 1e9+5
#define yes cout<<"YES"
#define no cout<<"NO"
#define nn "\n"
using namespace std;

int main(){
     #ifdef DarkLord
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif
ll test; cin>>test;
f(ttt,1,test){ 
 cout << "Case #" << ttt << ": ";
    
    ll n,m; cin>>n>>m;
    ll tree=0;
    vector<string> s;
    f(i,0,n-1){
        string t; cin>>t;
        f(j,0,m-1){
            if(t[j]=='^') tree++;
        }
        s.pb(t);
    }
    
    if((m==1 || n==1) && tree>0) {cout<<"Impossible"<<nn; continue;}
    if(tree==0){
        cout<<"Possible"<<nn;
        f(i,0,n-1){
            cout<<s[i]<<nn;
        }
        continue;
    }
    ll ck=0, cnt=0;
    f(i,0,n-1){
        f(j,0,m-1){
            cnt=0;
            if(i==0 && j==0){
                if(i+1<n && s[i+1][j]=='#') cnt++;
                if(j+1<m && s[i][j+1]=='#') cnt++;
                if(cnt==0 && s[i][j]=='.') s[i][j]='^';
            }else if(i==0 && j==m-1){
                if(i+1<n && s[i+1][j]=='#') cnt++;
                if(j-1>=0 && s[i][j-1]=='#') cnt++;
                if(cnt==0 && s[i][j]=='.') s[i][j]='^';
            }else if(i==n-1 && j==0){
                if(i-1>=0 && s[i-1][j]=='#') cnt++;
                if(j+1<m && s[i][j+1]=='#') cnt++;
                if(cnt==0 && s[i][j]=='.') s[i][j]='^';
            }else if(i==n-1 && j==m-1){
                if(i-1>=0 && s[i-1][j]=='#') cnt++;
                if(j-1>=0 && s[i][j-1]=='#') cnt++;
                if(cnt==0 && s[i][j]=='.') s[i][j]='^';
            }else if(s[i][j]!='#') s[i][j]='^';
        }
    }
    f(i,0,n-1){
        f(j,0,m-1){
            cnt=0;
            if(s[i][j]=='^'){
                if(i-1>=0 && s[i-1][j]=='^') cnt++;
                if(i+1<n && s[i+1][j]=='^') cnt++;
                if(j-1>=0 && s[i][j-1]=='^') cnt++;
                if(j+1<m && s[i][j+1]=='^') cnt++;
                if(cnt<2){ck=1; break;}
            }
            // cout<<cnt<<" ";
        }
        // cout<<nn;
    }
    if(ck) {cout<<"Impossible"<<nn; continue;}
    cout<<"Possible"<<nn;
    f(i,0,n-1){
        cout<<s[i]<<nn;
    }

}
    

}