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
    for(auto &e : a) cin >> e;

    ll l = 0;
    ll r = n- 1;
    ll la = 0;
    ll rb = 0;
    ll ans = 0;
    while (l <= r) {
        if (la <= rb) {
            la += a[l++];
        } else {
            rb += a[r--];
        }

        if (la == rb) {
            ans = max(ans, l + (n - 1 - r));
        }
    }
    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;\
    while (t--) {
        solve();
    }
    return 0;
}