#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb push_back
#define edl '\n'

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct s {
    stack<ll> s1;
    stack<ll> g;

    void push(ll x) {
        s1.push(x);
        g.push(g.empty() ? x : __gcd(x, g.top()));
    }

    ll pop() {
        ll x = s1.top();
        s1.pop();
        g.pop();
        return x;
    }

    bool is_empty() {
        return s1.empty();
    }

    ll getg() {
        return g.empty() ? 0 : g.top();
    }
};

::s sl, sr;

void add(ll x) {
    sr.push(x);
}

void remove() {
    if (sl.is_empty()) {
        while (!sr.is_empty()) {
            sl.push(sr.pop());
        }
    }
    sl.pop();
}

ll k;

bool good() {
    return __gcd(sl.getg(), sr.getg()) == 1;
}

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    for (auto &e : a)
        cin >> e;

    int ans = n  + 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        add(a[i]);
        while(good()) {
            ans = min(ans, i - j + 1);
            remove();
            j++;
        }
    }
    cout << (ans == n + 1 ? -1 : ans) << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}