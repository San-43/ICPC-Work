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

vi ans(MxN);
vector g(MxN, vector<int>());

ll dfs(int v, vector<ll> &a) {
    if(ans[v] != -1) return ans[v];
    if(g[v].empty()) return a[v];

    ll s = 0;
    for(int i = 0; i < sz(g[v]); i++) {
        s += dfs(g[v][i], a);
    }

    return ans[v] = min(a[v], s);
}


void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n+5);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = -1;
    }

    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        a[x] = 0;
    }

    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        g[i].clear();
        while(m--) {
            int x;
            cin >> x;
            g[i].pb(x);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dfs(i, a) << " ";
    }
    cout << edl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}