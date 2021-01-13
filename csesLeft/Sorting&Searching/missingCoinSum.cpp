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

// DON"T GET IMPULSIVEEEEEEE aaaaaaahh
 
ll INF = 2e17;
ll MOD = 1e9+7;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    SEND_HELP
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++ i) cin >> x[i];
    sort(x.begin(), x.end());

    if (x[0] != 1) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<ll> pre{x[0]};
    for (int i = 1; i < n; ++ i) {
        pre.push_back(pre.back() + x[i]);
    }

    for (int i = 0; i < n - 1; ++ i) {
        if (pre[i] + 1 < x[i + 1]) {
            cout << pre[i] + 1 << endl;
            return 0;
        }
    }    
  
    cout << pre[n - 1] + 1 << endl;
    return 0;
}
