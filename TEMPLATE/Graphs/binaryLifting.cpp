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


struct BLIFT_TREE {
 
    typedef long long int ll;

    struct EDGE {
        int src, nxt;
        ll w;
        EDGE(int src, int nxt, ll w) : src(src), nxt(nxt), w(w) {}

        bool operator< (const EDGE &o) const {
            return tie(w, nxt, src) < tie(o.w, o.nxt, o.src);
        }
    };    

    vector<vector<EDGE>> adj; // Adjacency list #INPUT 0-indexed
    int n; // No. of nodes #INPUT
    int root; // root of tree #INPUT

    vector<ll> dep; // weighted depth
    vector<int> d; // un weighted depth
    const int l = 18; // ~ log(n) + 1 
    vector<vector<int>> up;
    int dfsTime;
    vector<int> inTime, outTime;

    void reset() {
        adj.clear();
        dep.clear();
        d.clear();
        up.clear();
        inTime.clear();
        outTime.clear();   
    };

    void init(int N, int ROOT = 0) {
        reset();
        n = N;
        root = ROOT;
        adj.resize(n);
    }

    void addEdge(int a, int b, ll w = 1, bool bi = true) {
        adj[a].emplace_back(a, b, w);
        if (bi) adj[b].emplace_back(b, a, w);
    }

    void dfsDep(int u, int p) {
        inTime[u] = dfsTime ++;
        up[u][0] = p;
        for (EDGE &e : adj[u]) {
            if (e.nxt != p) {
                dep[e.nxt] = dep[u] + e.w;
                d[e.nxt] = d[u] + 1;
                dfsDep(e.nxt, u);
            }
        }
        outTime[u] = dfsTime ++;
    }

    void formUP() {
        dep.resize(n);
        inTime.resize(n);
        outTime.resize(n);
        d.resize(n);
        up.resize(n, vector<int>(l, -1));

        dfsTime = 0;
        dep[root] = 0;
        d[root] = 0;
        dfsDep(root, -1);

        for (int j = 1; j < l; ++ j) {
            for (int i = 0; i < n; ++ i) {
                if (up[i][j - 1] != -1)
                    up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    inline bool isAncestor(int u, int v) {
        return (inTime[u] <= inTime[v] && outTime[u] >= outTime[v]);
    }

    int moveUP(int u, int k) { // take K steps above u
        int cur = u;
        if (k > d[u])
            return root;
        if (k == 0)
            return cur;
        int left = k;
        while (left) {
            int steps = 0;
            while (steps < l && (1 << steps) <= left) ++ steps;
            -- steps;
            left -= (1 << steps);
            cur = up[cur][steps];
        }
        return cur;
    }

    int LCA(int u, int v) { // return 0 indexed
        if (dep[u] < dep[v])
            swap(u, v);
        u = moveUP(u, dep[u] - dep[v]);
        if (u == v) return u;
        int lo = 0;
        int hi = d[v];
        int lca = root;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int x = moveUP(u, mid);
            int y = moveUP(v, mid);
            if (x == y) {
                lca = x;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lca;
    }

    inline ll dist(int u, int v) {
        return (dep[u] + dep[v] - 2 * dep[LCA(u, v)]);
    }
};


int n, m;
struct BLIFT_TREE tree;
vector<pair<int, int>> paths;
vector<int> weight;
vector<int> ans;

void dfs(int u, int p = -1) {
    ans[u] = weight[u];
    for (auto e: tree.adj[u]) {
        if (e.nxt != p) {
            dfs(e.nxt, u);
            ans[u] += ans[e.nxt];
        }
    }
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    int n, m;
    cin >> n >> m;

    tree.init(n, 0);
    for (int i = 0; i < n - 1; ++ i) {
        int x, y;
        cin >> x >> y;
        -- x, -- y;
        tree.addEdge(x, y, true);
    }

    tree.formUP();
    weight.resize(n);
    ans.resize(n);

    while (m --) {
        int u, v;
        cin >> u >> v;

        -- u, -- v;

        weight[u] += 1;
        weight[v] += 1;

        auto lca = tree.LCA(u, v);
        // dbg(u + 1, v + 1, lca + 1);
        weight[lca] -= 1;
        if (tree.up[lca][0] != -1)
            weight[tree.up[lca][0]] -= 1;

        // dbg(weight);
    }

    dfs(0);
    
    for (auto it : ans) {
        cout << it << ' ';
    }

    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
