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

/* -------- */
inline ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}
inline ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
// BINARY EXP
ll expM(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// MOD INVERSE
inline ll iM(ll x, ll p) { // p is prime
    return expM(x, p - 2, p);
}
// MOD DIVISION
inline ll dM(ll a, ll b, ll p) {
    return ((a * iM(b, p)) % p);
}
// FACTORIAL
vector<ll> fact;
inline void formFactM(int N, ll p) {
    fact.push_back(1);
    for (int i = 1; i < N; ++ i)
        fact.push_back((fact.back() * i) % p);
}
// NCR MOD 
inline ll NCR (int N, int R, ll p) { // requires formation of fact
    assert (N >= R);
    if (N == R) return 1;
    return dM(fact[N], fact[R] * fact[N - R], p);
}
/* -------- */

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