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
    vector<vector<int>> spmin(20, vector<int>(n + 1));
    vector<vector<int>> spmax(20, vector<int>(n + 1));

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> spmin[0][i];
    }
    for(int i = 0; i < n; i++) {
        cin >> spmax[0][i];
        if(spmin[0][i] == spmax[0][i]) ans++;
    }

    for(int k = 1; k < 20; k++)
        for(int i = 0; i + (1 << k) <= n; i++) {
            spmin[k][i] = min(spmin[k - 1][i], spmin[k - 1][i + (1 << (k - 1))]);
            spmax[k][i] = max(spmax[k - 1][i], spmax[k - 1][i + (1 << (k - 1))]);
            if(spmin[k][i] == spmax[k][i])
                ans++;
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