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

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, d;
    cin >> n >> d;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans1 = 0;
    int ans2 = 0;
    auto ok = [&](ll m) {
        vi p(n + 1);
        vi mn(n + 1, LLINF);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i] - m;
            mn[i] = min(mn[i - 1], p[i]);
        }

        for (int i = 2; i <= n; i++) {
            if (i - d) {
                if (mn[i - d] <= p[i]) {
                    ans1 = i - d + 1;
                    ans2 = i + 1;
                    return true;
                }
            }
        }
        return false;
    };


    ll l = -1, r = LLINF;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (ok(m)) l = m;
        else r = m;
    }
    cout << ans1 << " " << ans2 << edl;
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