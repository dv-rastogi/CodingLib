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

template <typename T>
struct SEGTREE {

    struct NODE { // CHANGE
        T x;
    };  

    NODE merge(const NODE &A, const NODE &B) { // CHANGE
        return NODE{A.x + B.x};
    }

    NODE err() { // CHANGE
        return NODE{0};
    }

    vector<NODE> t, a;
    int n;
    
    void init(vector<T> A) { // initialize on vector
        n = A.size();
        t.resize(4 * n);
        for (auto it : A) 
            a.push_back(NODE{it});
        build(0, 0, n - 1);     
    }

    void build(int u, int tl, int tr) {
        if (tl == tr) {
            t[u] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(2 * u + 1, tl, tm);
        build(2 * u + 2, tm + 1, tr);
        t[u] = merge(t[2 * u + 1], t[2 * u + 2]);
    }

    void update(int idx, T val) { // CHANGE
        a[idx].x = val;
        _update(0, 0, n - 1, idx);
    }

    void _update(int u, int tl, int tr, int idx) {
        if (tl == tr) {
            t[u] = a[idx];
            return;
        }
        int tm = (tl + tr) >> 1;
        if(idx <= tm) _update(2 * u + 1, tl, tm, idx);
        else _update(2 * u + 2, tm + 1, tr, idx);
        t[u] = merge(t[2 * u + 1], t[2 * u + 2]);
    }

    NODE query(int l, int r) {
        if (l > r)
            return err();
        return _query(0, 0, n - 1, l , r);
    }

    NODE _query(int u, int tl, int tr, int l, int r) {
        if (tl == l && tr == r)
            return t[u];
        int tm = (tl + tr) >> 1;
        if(r <= tm) return _query(2 * u + 1, tl, tm, l, r);
        else if(l > tm) return _query(2 * u + 2, tm + 1, tr, l, r);
        else return merge(_query(2 * u + 1, tl, tm, l, tm), _query(2 * u + 2, tm + 1, tr, tm + 1, r));
    }
};

const int N = 2e5 + 5;
vector<ll> t(2 * N);
vector<int> adj[N];
int val[N];
int tim = 0;
int in[N];
int out[N];

void dfs(int u, int p) {
    t[in[u] = tim ++] = val[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    t[out[u] = tim ++] = -val[u];
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++ i) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        cin >> a >> b;
        -- a, -- b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    SEGTREE<ll> seg;
    seg.init(t);

    while (q --) {
        int cho;
        cin >> cho;
        if (cho == 1) {
            int u; ll x;
            cin >> u >> x;
            -- u;
            seg.update(in[u], x);
            seg.update(out[u], -x);
        } else {
            int u;
            cin >> u;
            -- u;
            cout << seg.query(0, 0, seg.n - 1, 0, in[u]).x << endl;
        }
    }

    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
