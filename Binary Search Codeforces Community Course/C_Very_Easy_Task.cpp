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
    ll n, x, y;
    cin >> n >> x >> y;
    if( x > y) swap(x, y);

    auto good = [&](ll t) {
        if(t < x) return false;

        ll tmp = t - x;
        ll total = 1 + tmp / x + tmp / y;
        return total >= n;
    };

    ll l = 0;
    ll r = y * n;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(good(mid)) {
            r = mid;
        } else l = mid + 1;
    }
    cout << l << edl;
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