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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<vector<ll>> b(m + 2);
    for (int i = 1; i <= n; i++) {
        int x;
        ll y, z;
        cin >> x >> y >> z;
        k -= y;
        int p = lower_bound(a.begin() + 1, a.end(), x) - a.begin(); 
        b[p].pb(z - y);
    }

    multiset<ll> st;
    ll ans = 0;

    for (int i = 1; i <= m + 1; i++) {
        for (ll w : b[i]) st.insert(w);

        if (i <= (int)m && !st.empty()) {
            auto it = prev(st.end());
            ans++;
            st.erase(it);
        }
    }

    for (ll w : st) {
        if (k >= w) {
            k -= w;
            ans++;
        } else break;
    }

    cout << ans << edl;
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
