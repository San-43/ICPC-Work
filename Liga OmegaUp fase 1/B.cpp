// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvi = vector<vi>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'
#define vsCode cout << flush, system("Pause")

constexpr long long LLINF = 2e18;
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int grid[MxN][MxN];
char chara[MxN][MxN];
int dp[MxN][MxN];
int bfs(const int& x, const int& y, const int& n) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return INF;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    if (x == n - 1 && y == n - 1) {
        return 1;
    }
    int derecha = bfs(x + 1, y, n);
    int izquierda = bfs(x, y + 1, n);

    int maxvalor = min(derecha, izquierda);

    int ans = chara[x][y] == 'l' ? grid[x][y] : chara[x][y] == 'b' ? -grid[x][y] : 0;

    return dp[x][y] = max(1, maxvalor - ans);

}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> chara[i][j];
        }
    }
    cout << bfs(0, 0, n) << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax