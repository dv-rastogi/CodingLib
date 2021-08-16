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

template<typename T>
struct SEGTREE_LAZY { 
    vector<T> t;
    vector<T> lazy; // contains the info, needed to be passed down
    vector<T> a;
    int n;
    
    void init(vector<T> A) {
        n = A.size();
        t.resize(4 * n);
        lazy.resize(4 * n);
        a = vector<T>(A);
        build(0, 0, n - 1);
    }

    // called when 2 child nodes merge to form parent node
    T merge(T a, T b) { 
        return a + b;
    }

    // called when change is need to be applied on a node
    void applyAggregate(int u, int tl, int tr, T change) {
        t[u] += change * (tr - tl + 1);
    }

    // called when a change is initiated at this node
    void initChange(int u, int tl, int tr, T change) {
        lazy[u] += change;
    }

    // called when parent node changes are to merged to child node
    void compose(int u, int tl, int tr, int p) {
        lazy[u] += lazy[p];
    }

    // called after changes are propogated 
    void reset(int u) {
        lazy[u] = 0;
    }

    // called when changes need to be pushed down while traversing
    void push(int u, int tl, int tr) {
        int tm = (tl + tr) >> 1;
        
        applyAggregate(2 * u + 1, tl, tm, lazy[u]);
        compose(2 * u + 1, tl, tm, u);

        applyAggregate(2 * u + 2, tm + 1, tr, lazy[u]);
        compose(2 * u + 2, tm + 1, tr, u);

        reset(u);
    }

    void build(int u, int tl, int tr) { // build
        if (tl == tr) {
            t[u] = a[tl];
        }
        else {
            int tm = (tl + tr) >> 1;
            build(2 * u + 1, tl, tm);
            build(2 * u + 2, tm + 1, tr);
            t[u] = merge(t[2 * u + 1] , t[2 * u + 2]);
        }
    }

    void update(int l, int r, T val) {
        _update(0, 0, n - 1, l, r, val);
    }

    void _update(int u, int tl, int tr, int l, int r, T val) { 
        if (l == tl && tr == r) {
            applyAggregate(u, tl, tr, val);
            initChange(u, tl, tr, val);
        }
        else {
            push(u, tl, tr);

            int tm = (tl + tr) >> 1;
            if (r <= tm)
                _update(2 * u + 1, tl, tm, l, r, val);
            else if (l > tm)
                _update(2 * u + 2, tm + 1, tr, l, r, val);
            else {
                _update(2 * u + 1, tl, tm, l, tm, val);
                _update(2 * u + 2, tm + 1, tr, tm + 1, r, val);
            }
            t[u] = merge(t[2 * u + 1], t[2 * u + 2]);
        }
    }

    T query(int l, int r) {
        return _query(0, 0, n - 1, l, r);
    }

    T _query(int u, int tl, int tr, int l, int r) { 
        if (l == tl && tr == r) {
            return t[u];
        }
        else {
            push(u, tl, tr);

            int tm = (tl + tr) >> 1;
            if (r <= tm)
                return _query(2 * u + 1, tl, tm, l, r);
            else if (l > tm)
                return _query(2 * u + 2, tm + 1, tr, l, r);
            else {
                T L = _query(2 * u + 1, tl, tm, l, tm);
                T R = _query(2 * u + 2, tm + 1, tr, tm + 1, r);
                return merge(L, R);
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
