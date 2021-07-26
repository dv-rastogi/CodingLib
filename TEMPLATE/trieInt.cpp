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
#ifdef LOCAL_PROJECT
    #define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define dbg(x...)
#endif

struct TRIE {
  
    struct NODE {
        int leaf;
        map<bool, int> next;
        map<bool, int> w;
        NODE() {
            leaf = 0;
        }
    };
    
    vector<NODE> nodes;
    
    void clear() {
        nodes.clear();
        nodes.resize(1);
    }
    
    TRIE() {
        clear();
    }
    
    void add(int x) {
        int u = 0;
        for (int i = 29; i >= 0; -- i) {
            bool bit = (x & (1 << i)) > 0;
            if (nodes[u].next.find(bit) == nodes[u].next.end()) {
                nodes[u].next[bit] = nodes.size();
                nodes.push_back(NODE{});
            }
            nodes[u].w[bit] ++;
            u = nodes[u].next[bit];
        }
        nodes[u].leaf ++;
    }

    void remove(int x, int u = 0, int at = 29) {    
        bool bit = (x & (1 << at)) > 0;
        nodes[u].w[bit] --;
        if (at != 0)
            remove(x, nodes[u].next[bit], at - 1);
        else {
            nodes[nodes[u].next[bit]].leaf --;
        }
    }
    

    bool exists(int x) {
        int u = 0;
        bool yes = true;
        for (int i = 29; i >= 0 && yes; -- i) {
            bool bit = (x & (1 << i)) > 0;
            if (nodes[u].next.find(bit) == nodes[u].next.end()) {
                yes = false;
                break;
            }
            yes &= (nodes[u].w[bit] > 0);
            u = nodes[u].next[bit];
        }
        return yes && (nodes[u].leaf > 0);
    }
};

int n;
vector<int> a;
vector<int> b;

void solve_tc(int test_case) {
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &ele: a) cin >> ele;
    for (auto &ele: b) cin >> ele;

    vector<int> possible;
    for (int i = 0; i < n; ++ i) {
        possible.push_back(a[0] ^ b[i]);
    }

    vector<int> answer;
    for (auto val: possible) {

        TRIE trie;
        for (int i = 0; i < n; ++ i) trie.add(b[i]);

        bool ok = true;
        for (int i = 0; i < n && ok; ++ i) {
            int look = val ^ a[i];
            if (trie.exists(look)) {
                trie.remove(look);
            } else {
                ok = false;
            }
        }

        if (ok)
            answer.push_back(val);

    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (auto it: answer) {
        cout << it << endl;
    }
}

int main() { 
    #ifdef LOCAL_PROJECT
        freopen("inputf.in", "r", stdin); // LINUX
    #endif
    SEND_HELP

    auto start_exec = chrono::high_resolution_clock::now();
    int tt = 1;
    // cin >> tt; // TEST CASE INPUT
    
    for (int tc = 1; tc <= tt; ++ tc) {
        solve_tc(tc);
    }

    auto stop_exec = chrono::high_resolution_clock::now();
    auto duration_exec = chrono::duration_cast<chrono::milliseconds>(stop_exec - start_exec);
    #ifdef LOCAL_PROJECT
        cout << "\n\nDURATION EXECUTION: " << duration_exec.count() << "ms\n";
    #endif

    return 0;
}

/*
https://github.com/watch24hrs-iiitd/CodingLib
*/
