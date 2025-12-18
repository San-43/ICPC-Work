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
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    map<pair<int, int>, int> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
        p[make_pair(a, b)]++;
    }
    ll ans = 0;
    for (auto &e : x) {
        ans += ((1LL * e.second * (e.second - 1)) / 2);
    }
    for (auto &e : y) {
        ans += ((1LL * e.second * (e.second - 1)) / 2);
    }
    for (auto &e : p) {
        ans -= ((1LL * e.second * (e.second - 1)) / 2);
    }
    cout << ans << edl;
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