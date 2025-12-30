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

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;

    vector<vi> cub(11, vector<ll>(11, 0));
    vi cub1(11, 0);
    vi cub2(11, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        ans += cub1[s[0] - 'a'] - cub[s[0] - 'a'][s[1] - 'a'];
        ans += cub2[s[1] - 'a'] - cub[s[0] - 'a'][s[1] - 'a'];

        cub1[s[0] - 'a']++;
        cub2[s[1] - 'a']++;
        cub[s[0] - 'a'][s[1] - 'a']++;
    }
    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}