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

bool dp[32][32];
void solve() {
    vi adj[32];
    int q, n;
    cin >> q >> n;
    while (q--) {
        char a, b, espacio;
        cin >> a >> b;
        dp[a - 'a'][b - 'a'] = true;
        adj[a - 'a'].pb(b - 'a');
    }
    for (int i = 0; i < 32; i++) {
        dp[i][i] = true;
    }
    for (int k = 0; k < 32; k++) {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                if (dp[i][k] && dp[k][j]) {
                    dp[i][j] = true;
                }
            }
        }
    }

    while (n--) {
        string x, y;
        cin >> x >> y;
        if (sz(x) != sz(y)) {
            cout << "no" << edl;
            continue;
        }
        bool band = false;
        for (int i = 0; i < sz(x); i++) {
            if (!dp[x[i] - 'a'][y[i] - 'a']) {
                cout << "no" << edl;
                band = true;
                break;
            }
        }
        if (!band) {
            cout << "yes" << edl;
        }
    }
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