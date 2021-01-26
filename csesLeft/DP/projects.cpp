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
ll MOD = 1e9+7;

struct task {
	int st, end;
	ll rew;
};

bool cc(const struct task &a, const struct task &b) {
	return a.end < b.end;
}

int main() { 
	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    #endif
    SEND_HELP

    int n;
    cin >> n;
    vector<struct task> t(n);
    for (int i = 0; i < n; ++ i) {
    	cin >> t[i].st >> t[i].end >> t[i].rew;
    }

    sort(t.begin(), t.end(), cc);

    for (auto it : t) {
    	dbg(it.st, it.end, it.rew);
    }

    vector<ll> dp(n);
    dp[0] = t[0].rew;
    
    for (int i = 1; i < n; ++ i) {

    	int lo = 0;
    	int hi = i - 1;
    	int cho = -1;
    	while (lo <= hi) {
    		int mid = (lo + hi) >> 1;
    		if (t[mid].end < t[i].st) {
    			cho = mid;
    			lo = mid + 1;
    		} else {
    			hi = mid - 1;
    		}
    	}
    	dbg(i, cho);
    	dp[i] = max(dp[i - 1], (cho == -1 ? 0 : dp[cho]) + t[i].rew);
    }

    dbg(dp);

    cout << dp.back();
    return 0;
}

/*

*/