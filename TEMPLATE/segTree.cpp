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

struct SEGTREE {
	vector<ll> t, a;
	int n;
	void init(vector<ll> A) {
		n = A.size();
		t.resize(4 * n);
		for (auto it : A) 
			a.push_back(it);
		build(0, 0, n - 1);		
	}
	void build(int u, int tl, int tr) {
	    if(tl == tr){
	        t[u] = a[tl];
	        return;
	    }
	    int tm = (tl + tr) >> 1;
	    build(2 * u + 1, tl, tm);
	    build(2 * u + 2, tm + 1, tr);
	    t[u] = min(t[2 * u + 1], t[2 * u + 2]);
	}
	void update(int u, int tl, int tr, int idx) { // update first the segArray
	    if(tl == tr){
	        t[u] = a[idx];
	        return;
	    }
	    int tm = (tl + tr) >> 1;
	    if(idx <= tm) update(2 * u + 1, tl, tm, idx);
	    else update(2 * u + 2, tm + 1, tr, idx);
	    t[u] = min(t[2 * u + 1], t[2 * u + 2]);
	}
	ll query(int u, int tl, int tr, int l, int r) {
	    if(tl == l && tr == r)
	        return t[u];
	    int tm = (tl + tr) >> 1;
	    if(r <= tm) return query(2 * u + 1, tl, tm, l, r);
	    else if(l > tm) return query(2 * u + 2, tm + 1, tr, l, r);
	    else return min(query(2 * u + 1, tl, tm, l, tm), query(2 *u + 2, tm + 1, tr, tm + 1, r));
	}
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr); // WINDOWS
    #endif
    SEND_HELP
    
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (int i = 0; i < n; ++ i) cin >> A[i];
    struct SEGTREE seg;
	seg.init(A);

	while(q --) {
		char cho;
		cin >> cho;
		if (cho == 'q') {
			int l, r;
			cin >> l >> r;
			cout << seg.query(0, 0, n - 1, -- l, -- r) << endl;
		}
		else {
			int x, y;
			cin >> x >> y;
			seg.a[-- x] = y;
			seg.update(0, 0, n - 1, x);
		}
	}
    
    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/