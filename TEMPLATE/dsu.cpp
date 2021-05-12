# include "bits/stdc++.h"
 
using namespace std;
 
#define endl "\n"
typedef long long int ll;
#define f first
#define s second
 
#define SEND_HELP ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
// DEBUG
void __print(int x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int _ = 0; cerr << '{'; for (auto& i : x) cerr << (_++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
    #define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define dbg(x...)
#endif
 
ll INF = 2e17;
ll MOD = 1e9 + 7;

struct DSU {
    vector<int> par, sz;
    int n; 
    void init(int lim) {
        n = lim;
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++ i) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v) {
        if (v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    
    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
