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
    string r;
    cin >> r;
    int ans = 0;
    if (r[0] == 'u') {
        r[0] = 's';
        ans++;
    }
    if (r[r.size() - 1] == 'u') {
        r[r.size() - 1] = 's';
        ans++;
    }
    for (int i = 1; i < r.size() - 1; i++) {
        if (r[i] == 'u') {
            if(r[i+1] != 's') {
                r[i+1] = 's';
                ans += 1;
            }
        }
    }

    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}