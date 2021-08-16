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


struct SCC {
    vector<vector<int>> adj; // INIT, 0 indexed nodes, take care of self loops
    int n; // INIT
    vector<vector<int>> radj;
    vector<bool> vis;
    vector<int> topo;
    vector<vector<int>> scc;

    void formTranspose() {
        radj.resize(n);
        for (int i = 0; i < (int) adj.size(); ++ i) {
            for (int j = 0; j < (int) adj[i].size(); ++ j)
                radj[adj[i][j]].push_back(i);
        }
    }

    void dfs(int u) {
        vis[u] = true;
        for (auto v : adj[u])
            if (!vis[v])
                dfs(v);
        topo.push_back(u);
    }

    void dfsR(int u) {
        vis[u] = true;
        scc.back().push_back(u);
        for (auto v : radj[u]) {
            if (!vis[v]) {
                dfsR(v);
            }
        }
    }

    vector<vector<int>> getScc() {

        formTranspose();

        vis.clear();
        vis.resize(n, 0);
        for (int i = 0; i < n; ++ i) {
            if (!vis[i]) 
                dfs(i);
        }

        reverse(topo.begin(), topo.end());
        vis.clear(); scc.clear();
        vis.resize(n, 0);
        for (int i = 0; i < n; ++ i) {
            if (!vis[topo[i]]) {
                scc.push_back(vector<int>());
                dfsR(topo[i]);
            }
        }

        return scc;
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
