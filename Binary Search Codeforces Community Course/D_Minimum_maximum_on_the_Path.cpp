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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n+1);
    int l = -1;
    int r = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        r = max(r, c);
    }

    vector<int> d(n+1), ans(n+1);
    auto ok = [&](int mid, bool band) {
        queue<int> q;
        fill(d.begin(), d.end(), INF);
        if (band) {
            fill(ans.begin(), ans.end(), -1);
            ans[1] = 0;
        }

        d[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (d[x] == k) continue;

            for (auto &i : graph[x]) {
                int u = i.fi;
                int w = i.se;
                if (w > mid) continue;
                if (d[u] != INF) continue;

                d[u] = d[x] + 1;
                q.push(u);
                if (band) ans[u] = x;
            }
        }
        return d[n] <= k;
    };

    if (!ok(r, false)) {
        cout << -1 << edl;
        return;
    }

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (ok(m, false)) r = m;
        else l = m;
    }

    ok(r, true);

    vector<int> resp; // camino desde n hasta 1
    int cur = n;
    while (cur != 0) {
        resp.pb(cur);
        if (cur == 1) break;
        cur = ans[cur];
    }
    reverse(resp.begin(), resp.end()); // para imprimir en orden.
    cout << resp.size() - 1 << edl;
    for (auto i : resp) {
        cout << i << " ";
    }
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