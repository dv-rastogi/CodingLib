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

ll inv = 0;
vector<int> x;

void join(int l, int r) {
    int mid = (l + r) >> 1;
    int sl = mid - l + 1;
    int sr = r - mid;
    vector<int> left(sl), right(sr);
    for (int i = 0, j = l; i < sl; ++ i, ++ j)
        left[i] = x[j];
    for (int i = 0, j = mid + 1; i < sr; ++ i, ++ j)
        right[i] = x[j];

    vector<int> f;
    int pl = 0, pr = 0;
    while (pl < sl && pr < sr) {
        if (left[pl] > right[pr]) {
            f.push_back(right[pr ++]);
        } else {
            f.push_back(left[pl ++]);
            inv += pr;
        }
    }

    while (pl < sl) {
        f.push_back(left[pl ++]);
        inv += sr;
    }

    while (pr < sr) {
        f.push_back(right[pr ++]);
    }

    for (int i = 0, j = l; i < (int) f.size(); ++ i, ++ j)
        x[j] = f[i];
}

void msort(int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    join(l, r);
}

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("debug.txt", "w", stderr); // WINDOWS
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP
    
    int tt;
    cin >> tt;
    while (tt --) {
        int n;
        cin >> n;
        
        x.clear();
        x.resize(n);
        for (int i = 0; i < n; ++ i) {
            cin >> x[i];
        }

        inv = 0;
        msort(0, n - 1);
        cout << inv << endl;
    }
    
    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/