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
    
   	int n, m;
   	cin >> n >> m;

   	multiset<int> h;
   	for (int i = 0, x; i < n; ++ i) {
   		cin >> x;
   		h.insert(x);
   	}

   	for (int i = 0, c; i < m; ++ i) {
   		cin >> c;
   		auto pos = h.upper_bound(c);
   		if (pos == h.begin()) cout << -1 << " ";
   		else {
   			-- pos;
   			cout << *pos << " ";
   			h.erase(pos);
   		}
   		cout << endl;
   	}
    
    return 0;
}
