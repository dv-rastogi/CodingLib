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
ll MOD = 1e9 + 7;

struct SEGTREE_LAZY { // sum of range
	vector<ll> t, lazy;
	vector<ll> a;
	int n;
	void init(vector<ll> A) { // init the segTree
		n = A.size();
		t.resize(4 * n);
		lazy.resize(4 * n);
		for (auto it : A)
			a.push_back(it);

		this->build(0, 0, n - 1);
	}
	void build(int u, int tl, int tr) { // build
		if (tl == tr) {
			t[u] = a[tl];
		}
		else {
			int tm = (tl + tr) >> 1;
			build(2 * u + 1, tl, tm);
			build(2 * u + 2, tm + 1, tr);
			t[u] = t[2 * u + 1] + t[2 * u + 2];
		}
	}
	void update(int u, int tl, int tr, int l, int r, ll val) { // update
		if (l == tl && tr == r) {
			t[u] += val * (r - l + 1);
			{ // lazy
				lazy[u] += val;
			}
		}
		else {
			int tm = (tl + tr) >> 1;
			{ // perform lazy push
				lazy[2 * u + 1] += lazy[u];
				t[2 * u + 1] += (lazy[u] * (tm - tl + 1));
				lazy[2 * u + 2] += lazy[u];
				t[2 * u + 2] += (lazy[u] * (tr - tm));
				lazy[u] = 0;
			}
			if (r <= tm)
				update(2 * u + 1, tl, tm, l, r, val);
			else if (l > tm)
				update(2 * u + 2, tm + 1, tr, l, r, val);
			else {
				update(2 * u + 1, tl, tm, l, tm, val);
				update(2 * u + 2, tm + 1, tr, tm + 1, r, val);
			}
			t[u] = t[2 * u + 1] + t[2 * u + 2];
		}
	}
	ll query(int u, int tl, int tr, int l, int r) { // update
		if (l == tl && tr == r) {
			return t[u];
		}
		else {
			int tm = (tl + tr) >> 1;
			{ // perform lazy push
				lazy[2 * u + 1] += lazy[u];
				t[2 * u + 1] += (lazy[u] * (tm - tl + 1));
				lazy[2 * u + 2] += lazy[u];
				t[2 * u + 2] += (lazy[u] * (tr - tm));
				lazy[u] = 0;
			}
			if (r <= tm)
				return query(2 * u + 1, tl, tm, l, r);
			else if (l > tm)
				return query(2 * u + 2, tm + 1, tr, l, r);
			else {
				ll lsum = query(2 * u + 1, tl, tm, l, tm);
				ll rsum = query(2 * u + 2, tm + 1, tr, tm + 1, r);
				return lsum + rsum;
			} 

		}
	}
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr); // WINDOWS
    #endif
    SEND_HELP
    
    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/