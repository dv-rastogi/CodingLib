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
#ifdef LOCAL_PROJECT
    #define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define dbg(x...)
#endif

const ll INF = 2e17;
const ll MOD = 1e9 + 7;

const int N = 2005;

struct DJIKSTRA {
    
    struct EDGE {
        int src, nxt;
        ll w;
        EDGE(int src, int nxt, ll w) : src(src), nxt(nxt), w(w) {}

        bool operator< (const EDGE &o) const {
            return tie(w, nxt, src) < tie(o.w, o.nxt, o.src);
        }
    }; 

    int N, ROOT;
    vector<vector<EDGE>> ADJ;
    vector<int> PAR;
    vector<ll> DEP;

    DJIKSTRA(int n, int r): N(n), ROOT(r) {
        ADJ.resize(N);
        PAR.resize(N);
        DEP.resize(N, INF);
    }

    void addEdge(int u, int v, ll w, bool bi = true) {
        ADJ[u].emplace_back(u, v, w);
        if (bi) ADJ[v].emplace_back(v, u, w);
    }

    void form() {

        DEP[ROOT] = 0;
        set<pair<ll, int>> S;
        for (int i = 0; i < N; ++ i) {
            S.insert({DEP[i], i});
        }

        while (!S.empty()) {
            auto [dist, u] = *S.begin();
            S.erase(S.begin());

            for (EDGE e: ADJ[u]) {
                if (DEP[e.nxt] > dist + e.w) {
                    assert (S.find({DEP[e.nxt], e.nxt}) != S.end());
                    S.erase({DEP[e.nxt], e.nxt});
                    DEP[e.nxt] = dist + e.w;
                    S.insert({DEP[e.nxt], e.nxt});
                    PAR[e.nxt] = u;
                }
            }
        }
    
    }
};

void solve_tc(int test_case) {
    int n, m;
    cin >> n >> m;
    DJIKSTRA djik(n, 0);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        djik.addEdge(-- u, -- v, w, false);
    }

    djik.form();
    for (auto it: djik.DEP) {
        cout << it << ' ';
    }
}

int main() { 
    #ifdef LOCAL_PROJECT
        freopen("inputf.in", "r", stdin); 
        freopen("outputf.in", "w", stdout); // WIN 
        freopen("debug.txt", "w", stderr); // WIN
    #endif
    SEND_HELP
    auto start_exec = chrono::high_resolution_clock::now();
    int tt = 1;
    // cin >> tt; // TEST CASE INPUT
    
    for (int tc = 1; tc <= tt; ++ tc) {
        solve_tc(tc);
    }
    auto stop_exec = chrono::high_resolution_clock::now();
    auto duration_exec = chrono::duration_cast<chrono::milliseconds>(stop_exec - start_exec);
    #ifdef LOCAL_PROJECT
        cout << "\n\nDURATION EXECUTION: " << duration_exec.count() << "ms\n";
    #endif
    return 0;
}
/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
