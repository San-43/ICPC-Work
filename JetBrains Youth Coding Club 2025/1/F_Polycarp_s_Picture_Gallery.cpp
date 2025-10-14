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

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for(auto &e : v) cin >> e;

    vector<pair<int, int>> c;
    ll s = 0;
    for(int i = 0; i < m; i++) {
        int x = min(v[i], n / 2);
        c.emplace_back(x, i);
        s += x;
    }
    sort(c.rbegin(), c.rend());
    if(s < n) {
        cout << -1 << edl;
        return;
    }

    vector<int> ans(n);
    int x = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(!(n&1) && i == n / 2) x++;
        c[j].first--;
        ans[x] = c[j].second;
        if(c[j].first == 0) j++;
        x = (x + 2) % n;
    }
    for(auto x : ans) cout << x + 1 << " ";
    cout << edl;
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