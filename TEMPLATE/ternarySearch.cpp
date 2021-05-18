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

// Prob: https://codeforces.com/problemset/problem/439/D
void solve_tc(int test_case) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < m; ++ i) cin >> b[i];

    auto f = [&](int k) -> ll {
        ll c1 = 0;
        for (const auto &it: a) c1 += max(0, k - it);
        ll c2 = 0;
        for (const auto &it: b) c2 += max(0, it - k);
        return c1 + c2;
    };

    int l = 1;
    int r = 1e9;

    while (r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        auto f1 = f(m1);
        auto f2 = f(m2);

        if (f1 < f2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    ll ops = INF;
    for (int i = l; i <= r; ++ i)
        ops = min(ops, f(i));
    cout << ops << '\n';
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
