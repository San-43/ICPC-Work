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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi p(n + 5, 0), s(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        p[i] = p[i - 1] + llabs(a[i]);
    }
    
    for (int i = n; i >= 1; i--) {
        s[i] = s[i + 1] + a[i];
    }

    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ll l = 0;
        ll r = 0;
        if (i > 1) {
            l = a[1] + p[i - 1];
        }
        r = s[i + 1];
        ans = max(ans, l - r);
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