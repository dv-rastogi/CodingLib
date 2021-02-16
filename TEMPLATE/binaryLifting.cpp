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
    vector<vector<pair<int, ll>>> adj; // Adjacency list #INPUT 0-indexed
    int n; // No. of nodes #INPUT
    int root; // root of tree #INPUT

    vector<ll> dep; // weighted depth
    vector<int> d; // un weighted depth
    const int l = 18; // ~ log(n) + 1 
    vector<vector<int>> up;
    int dfsTime;
    vector<int> inTime, outTime;

    void init(vector<vector<int>> &ADJ, int N, int ROOT = 0) {
        n = N;
        root = ROOT;
        adj.resize(N);

        for (int i = 0; i < n; ++ i) {
            for (auto it : ADJ[i]) {
                adj[i].push_back({it, 1});
            }
        }

        formUP();
    }

    void initD(vector<vector<pair<int, ll>>> &ADJ, int N, int ROOT = 0) { // FOR DEPTH
        n = N;
        root = ROOT;
        adj = ADJ;

        formUP();
    }

    void dfsDep(int u, int p) {
        inTime[u] = dfsTime ++;
        up[u][0] = p;
        for (auto v : adj[u]) {
            if (v.f != p) {
                dep[v.f] = dep[u] + v.s;
                d[v.f] = d[u] + 1;
                dfsDep(v.f, u);
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
            return -1;
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


int main() { 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++ i) {
        int e;
        cin >> e;
        -- e;
        adj[e].push_back(i);
    }

    struct BLIFT_TREE tree;
    tree.init(adj, n);

    while (q --) {
        int x, y;
        cin >> x >> y;
        -- x, --y;
        int ans = tree.LCA(x, y) + 1;
        cout << ans << endl;
    }

    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/