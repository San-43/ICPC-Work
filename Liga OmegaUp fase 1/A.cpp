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
    ll n, p;
    cin >> n >> p;
    vector<vector<int>> a(n);
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<bool> vis(n, 0);
    ll total = (n * (n - 1)) / 2;
    ll tmp = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            ll cnt = 0;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                cnt++;
                for (auto j : a[x]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
            tmp += (cnt * (cnt - 1)) / 2;
        }
    }

    cout << total - tmp << edl;
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