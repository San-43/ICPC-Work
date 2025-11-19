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
int n, m, k;


void solve() {
    cin >> n >> m >> k;
    vector<string> name(n);
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m)), c(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        cin >> name[i];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j] >> b[i][j] >> c[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            vector<pair<int, int>> v;
            for (int g = 0; g < m; g++) {
                if (b[i][g] - a[j][g] > 0) {
                    v.emplace_back(b[i][g] - a[j][g], c[j][g]);
                }
            }

            ranges::sort(v, greater<pair<int, int>>());
            int count = 0;
            int sum = 0;
            for (auto p : v) {
                if (count >= k) break;
                const int tmp = min(p.second, k - count);
                sum += tmp * p.first;
                count += tmp;
            }
            ans = max(ans, sum);
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