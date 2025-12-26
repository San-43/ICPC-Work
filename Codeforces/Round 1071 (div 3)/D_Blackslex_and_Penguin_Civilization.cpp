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
    vector<vector<ll>> v(n + 1);
    v[0].push_back(0);
    
    for (int i = 1; i <= n; i++) {
        vi a;
        for (const auto j : v[i - 1])
            a.pb(j * 2 + 1);
        for (ll j = 0; j < (1LL << i); j += 2)
            a.pb(j);
        v[i] = a;
    }

    for (const auto i : v[n]) cout << i << " ";
    cout << edl;
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