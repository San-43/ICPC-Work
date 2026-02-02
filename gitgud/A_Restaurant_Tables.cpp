#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
constexpr int dxx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    int one = 0, two = 0, bb = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            if (a == 0) {
                if (b == 0) {
                    if (bb == 0) {
                        ans += 1;
                    } else {
                        bb -= 1;
                    }
                } else {
                    b -= 1;
                    bb += 1;
                }
            } else {
                a -= 1;
            }
        } else {
            if (b == 0) {
                ans += 2;
            } else {
                b--;
            }
        }
    }
    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}