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
    
    int tt;
    cin >> tt;
    while (tt --) {
        string s;
        int n, q;
        cin >> n >> q;
        cin >> s;
        while (q --) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            string t = s.substr(l, r - l + 1);
            char nl = t[0];
            char nr = t[t.size() - 1];
            bool ok = 0;
            for (int i = 0; i < l; ++ i) 
                if (nl == s[i]) ok = 1;
            for (int i = r + 1; i < n; ++ i)
                if (nr == s[i]) ok = 1;
            if (t.size() >= 2 && ok) puts("YES");
            else puts("NO");
        }
    }
    
    
    return 0;
}
