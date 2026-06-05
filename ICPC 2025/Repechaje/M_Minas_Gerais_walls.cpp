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

constexpr long long LLINF = 4e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(auto &e : v)
        cin >> e;

    // 1) Prefix / suffix minima of original x (for untouched regions)
    vi pr(n), sf(n);
    for (int i = 0; i < n; ++i)
        pr[i] = (i ? min(pr[i-1], v[i]) : v[i]);
    for (int i = n - 1; i >= 0; --i)
        sf[i] = (i + 1 < n ? min(sf[i + 1], v[i]) : v[i]);

    // 2) Sliding-window mins of y = x + i over windows [max(0, r-K+1) .. r]
    vi y(n), mplus(n);
    for (int i = 0; i < n; ++i) y[i] = v[i] + i;

    deque<int> dq; // increasing by y[]
    for (int r = 0; r < n; ++r) {
        while (!dq.empty() && y[dq.back()] >= y[r]) dq.pop_back();
        dq.push_back(r);
        int L = r - k + 1;              // left bound of the window
        while (!dq.empty() && dq.front() < L) dq.pop_front();
        mplus[r] = y[dq.front()];
    }

    // 3) Evaluate M(r) for all r; take the best
    ll ans = 0; // heights >=1, so 0 is safe start
    for (int r = 0; r < n; ++r) {
        ll left  = (r >= k ? pr[r - k] : LLINF);
        ll mid   = mplus[r] + (k - r);      // constant shift in the window
        ll right = (r + 1 < n ? sf[r + 1] : LLINF);
        ll cur = min(left, min(mid, right));
        ans = max(ans, cur);
    }

    cout << ans << '\n';
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