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
    vi a(n), c(n);

    for(auto &e : a) cin >> e;

    ll sum = 0;
    for(auto &e : c) {
        cin >> e;
        sum += e;
    }

    vi dp(n, 0);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        dp[i] = c[i];
        for(int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << (sum - ans) << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}