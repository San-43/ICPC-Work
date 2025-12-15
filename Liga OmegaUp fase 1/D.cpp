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

char arr[MxN][MxN];
bool visited[MxN][MxN];
bool dfs(const int& x, const int& y, const int& n, const int& m) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    if (visited[x][y] || arr[x][y] == '#') {
        return false;
    }
    visited[x][y] = true;
    if (arr[x][y] == 'S') {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        if (dfs(x + dx[i], y + dy[i], n, m)) {
            return true;
        }
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int x, y;
    string aux;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, aux);
        for (int j = 0; j < m; j++) {
            arr[i][j] = aux[j];
            if (arr[i][j] == 'E') {
                x = i;
                y = j;
            }
        }
    }

    cout << (dfs(x, y, n, m) ? "Si": "No") << edl;
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