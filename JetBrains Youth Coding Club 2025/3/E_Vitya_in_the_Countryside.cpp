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
    vi a(n);
    for(auto &e : a) cin >> e;

    if (n == 1) {
        if (a[0] == 15) cout << "DOWN" << edl;
        else if (a[0] == 0) cout << "UP" << edl;
        else cout << -1 << edl;
    } else {
        if (a[n - 2] < a[n - 1]) {
            if (a[n - 1] == 15) cout << "DOWN" << edl;
            else cout << "UP" << edl;
        } else {
            if (a[n - 1] == 0) cout << "UP" << edl;
            else cout << "DOWN" << edl;
        }
    }
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