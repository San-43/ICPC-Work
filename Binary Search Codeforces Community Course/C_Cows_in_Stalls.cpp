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
    for (auto &e : a) cin >> e;



    auto ok = [&](ll m) {
        ll tmp = a[0];
        ll count = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - tmp >= m) {
                count++;
                tmp = a[i];
            }
        }
        return count >= k;
    };

    ll l = 0;
    ll r = 1e13;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (ok(m)) l = m;
        else r = m;
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