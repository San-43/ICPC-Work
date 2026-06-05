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
    int n, c;
    cin >> n >> c;

    vector<bool> cub(c + 5, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cub[x] = 1;
    }

    if (!cub[1]) {
        cout << "No" << edl;
        return;
    }

    vector<int> nxt(c + 3, c + 1);
    for (int i = c; i >= 1; --i) {
        nxt[i] = cub[i] ? i : nxt[i + 1];
    }

    bool ok = true;
    int ans = 0;

    for (int i = 1; i <= c && ok; ++i) {
        if (!cub[i])
            continue;

        int l = i;
        while (l <= c) {
            int x = nxt[l];
            if (x > c)
                break;

            int q = x / i;
            if (!cub[q]) {
                ok = false;
                ans = q;
                break;
            }

            l = (q + 1) * i;
        }
    }

    if (ok)
        cout << "Si" << edl;
    else
        cout << "No " << ans << edl;
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