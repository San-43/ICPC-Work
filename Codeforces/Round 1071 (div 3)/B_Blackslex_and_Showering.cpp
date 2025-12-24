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
    int n;
    cin >> n;
    vi a(n);
    for(auto &e : a) {
        cin >> e;
    }

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += llabs(a[i] - a[i + 1]);
    }

    ll ans = sum;
    ans = min(ans, sum - llabs(a[0] - a[1]));
    ans = min(ans, sum - llabs(a[n - 2] - a[n - 1]));
    for (int i = 1; i <= n - 2; i++) {
        ll tmp = sum - llabs(a[i - 1] - a[i])
                - llabs(a[i] - a[i + 1])
                + llabs(a[i - 1] - a[i + 1]);
        ans = min(ans, tmp);
    }
    cout << ans << edl;
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