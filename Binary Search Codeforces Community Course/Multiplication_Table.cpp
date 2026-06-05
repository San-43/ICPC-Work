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
constexpr int dxx[8] = { 1,  1,  0, -1, -1, -1,  0,  1};
constexpr int dyy[8] = { 0,  1,  1,  1,  0, -1, -1, -1};


void solve() {
    ll n;
    cin >> n;

    ll k = (n*n+1) / 2;

    auto ok = [&](const ll mid) {
        ll count = 0;
        for (int i = 1; i <= n; i++) {
            count += min(n, mid/i);
        }
        return count;
    };

    ll l = 1;
    ll r = n*n;
    while (l < r) {
        const ll mid = (l + r) / 2;
        if (ok(mid) >= k) {
            r = mid;
        } else
            l = mid + 1;
    }
    cout << l << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}