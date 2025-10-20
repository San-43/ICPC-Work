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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;

    ll ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            ++i;
        } else if (a[i] > b[j]) {
            ++j;
        } else {
            ll val = a[i];
            ll cntA = 0, cntB = 0;
            while (i < n && a[i] == val) { ++cntA; ++i; }
            while (j < m && b[j] == val) { ++cntB; ++j; }
            ans += cntA * cntB;
        }
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