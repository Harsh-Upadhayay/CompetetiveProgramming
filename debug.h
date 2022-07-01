#include <bits/stdc++.h>

using namespace std;
/*************************************************************************************************************************************/
template<class T, class V>
void __print (const unordered_map<T, list<V>> &x){
    cerr << "\n{\n";
    for(auto y : x){
        cerr << y.first << " : ";
        for(auto z : y.second)
            cerr << z << " ";
        cerr << "\n";
    }
    cerr << "}\n";
}
template<class T, class V>
void __print (const unordered_map<T, vector<V>> &x){
    cerr << "\n{\n";
    for(auto y : x){
        cerr << y.first << " : ";
        for(auto z : y.second)
            cerr << z << " ";
        cerr << "\n";
    }
    cerr << "}\n";
}
template<class T, class V>
void __print (const map<T, list<V>> &x){
    cerr << "\n{\n";
    for(auto y : x){
        cerr << y.first << " : ";
        for(auto z : y.second)
            cerr << z << " ";
        cerr << "\n";
    }
    cerr << "}\n";
}
template<class T, class V>
void __print (const map<T, vector<V>> &x){
    cerr << "\n{\n";
    for(auto y : x){
        cerr << y.first << " : ";
        for(auto z : y.second)
            cerr << z << " ";
        cerr << "\n";
    }
    cerr << "}\n";
}
/*************************************************************************************************************************************/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{'; __print(x.first);
    cerr << ','; __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) 
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() {
    cerr << "]\n";
}

template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
     _print(v...);
}

#define debug(x...) cerr << "Line(" << __LINE__ << ") " << "[" << #x << "] = ["; _print(x)