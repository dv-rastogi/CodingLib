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
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int _ = 0; cerr << '{'; for (auto& i : x) cerr << (_++ ? ", " : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
    #define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define dbg(x...)
#endif

// DON"T GET IMPULSIVEEEEEEE aaaaaaahh
 
ll INF = 2e17;
ll MOD = 1e9+7;

int n, m;
vector<int> x;
vector<vector<ll>> dp;

ll calc(int pos, int prev) {
    if (prev <= 0 || prev > m) return 0;
    if (pos == n) return 1;
    if (x[pos] != 0 && abs(x[pos] - prev) > 1) return 0;
    
    ll &ans = dp[pos][prev];
    if (ans != -1) {
        return ans;
    } 
    if (x[pos] != 0) {
        ans = calc(pos + 1, x[pos]);
    } else {
        ans = calc(pos + 1, prev - 1) + calc(pos + 1, prev) + calc(pos + 1, prev + 1);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("inputf.in", "r", stdin); // LINUX
        freopen("debug.txt", "w", stderr); // WINDOWS
    #endif  
    SEND_HELP
    
    cin >> n >> m;
    dp.resize(n, vector<ll>(m + 1, -1));
    x.resize(n);
    for (int i = 0; i < n; ++ i) cin >> x[i];

    ll ans = 0;
    if (x[0] == 0) {
        for (int j = 1; j <= m; ++ j)
            ans += calc(1, j);
    } else {
        ans = calc(1, x[0]);
    }

    cout << ans;
    return 0;
}
