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

struct segTreeMin {
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

struct segTreeMax {
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
	    t[u] = max(t[2 * u + 1], t[2 * u + 2]);
	}
	void update(int u, int tl, int tr, int idx) { // update first the segArray
	    if(tl == tr){
	        t[u] = a[idx];
	        return;
	    }
	    int tm = (tl + tr) >> 1;
	    if(idx <= tm) update(2 * u + 1, tl, tm, idx);
	    else update(2 * u + 2, tm + 1, tr, idx);
	    t[u] = max(t[2 * u + 1], t[2 * u + 2]);
	}
	ll query(int u, int tl, int tr, int l, int r) {
	    if(tl == l && tr == r)
	        return t[u];
	    int tm = (tl + tr) >> 1;
	    if(r <= tm) return query(2 * u + 1, tl, tm, l, r);
	    else if(l > tm) return query(2 * u + 2, tm + 1, tr, l, r);
	    else return max(query(2 * u + 1, tl, tm, l, tm), query(2 *u + 2, tm + 1, tr, tm + 1, r));
	}
}; 

int main() {
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    SEND_HELP
    
    int tt;
    cin >> tt;
    while (tt --) {
    	int n;
    	cin >> n;
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++ i) cin >> a[i];

    	segTreeMin segMi;
   		segTreeMax segMx;
   		segMi.init(a);
   		segMx.init(a);	

    	map<int, vector<int>> idx;
    	map<int, bool> done;
    	for (int i = 0; i < n; ++ i) {
    		idx[a[i]].push_back(i);
    	}

    	int ml = -1, mr = -1;
    	ll mxr = -1;
    	for (int r = n - 1; r >= 2; -- r) {
    		// this is the start of the last seg
    		mxr = max(mxr, a[r]);
    		// if (done[mxr]) continue;
    		done[mxr] = true;
    		dbg(mxr);

    		vector<int> pos = idx[mxr];
     		int cur = lower_bound(pos.begin(), pos.end(), r) - pos.begin();
     		cur --;

     		if (cur < 1) continue; // at least need two occurences bef.
     		
     		dbg(idx[mxr], pos[cur]);
     		for (; cur > 0; -- cur) {
     			int m = pos[cur]; // this is the idx of min value of mid seg.
     			
     			// check if m -> r - 1, this is min
     			assert (r - 1 >= m);
     			int minCheck = segMi.query(0, 0, n - 1, m, r - 1);
     			if (minCheck < a[m]) continue; // this can't be min

     			// this is min
     			int lo = 0;
     			int hi = m - 1;
     			int ans = -1;
     			while (lo <= hi) {
     				int mid = (lo + hi) >> 1;

     				assert (mid <= m - 1);
     				int maxCheck = segMx.query(0, 0, n - 1, mid, m - 1);
     				if (maxCheck > a[m]) {
     					ans = mid;
     					hi = mid - 1;
     				}
     				else {
     					lo = mid + 1;
     				}
     			}

     			if (ans != -1) {
     				ml = ans;
     				mr = m;
     			}
     		}

     		if (ml != -1) {
     			break;
     		}    	
    	}

	    if (ml == -1) {
	    	puts("NO");
	    }
	    else {
	 		puts("YES");
	    	cout << ml << " " << (mr - ml + 1) << " " << (n - (ml) - (mr - ml + 1)) << endl;
	    }
	}
    
    return 0;
}
