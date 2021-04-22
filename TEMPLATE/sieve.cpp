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

vector<int> sieve(int n) {
	vector<int> prime(n + 1, 1); // stores the smallest factor, bounce down while factoring
	for (int p = 2; p * p <= n; ++ p) {
		if (prime[p] == 1) {
			for (int i = p * p; i <= n; i += p) {
				if (prime[i] != 1) continue;
				prime[i] = p;
			}
		}
	}
	return prime;
}

int main() { 
	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    
    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
