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
    int n, k;
    cin >> n >> k;
    vi a(n);
    ll l = 0;
    ll r = 0;
    for (auto&e : a) {
        cin >> e;
        r += e;
        l = max(l, e);
    }

    auto ok = [&](ll m) -> bool {
        int count = 1;
        ll sum = 0;
        for (auto &e : a) {
            if (sum + e <= m) {
                sum += e;
            } else {
                sum = 0;
                sum += e;
                count++;
            }
        }
        // cerr << count << endl;
        return count <= k;
    };

    while(l < r) {
        ll m = l + (r - l) / 2;
        if (ok(m)) r = m;
        else l = m + 1;
    }
    cout << l << edl;
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