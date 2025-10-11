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
    int n, a, b;
    cin >> n >> a >> b;

    auto ok = [&](int x) {
        if(x == 0) return true;
        int l = max(1, n - b/x);
        int r = min(n - 1, a / x);
        return l <= r;
    };

    int lo = 0, hi = max(a, b);
    while(lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if(ok(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << edl;
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