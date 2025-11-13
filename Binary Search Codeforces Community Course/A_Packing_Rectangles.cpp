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

ll w, h, n;

bool good(ll x) {
    return (x / w) * (x / h) >= n;
}

void solve() {
    cin >> w >> h >> n;

    ll l, r;
    l = 0;
    r = 1;
    while (!good(r))
        r *= 2;

    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << edl;
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