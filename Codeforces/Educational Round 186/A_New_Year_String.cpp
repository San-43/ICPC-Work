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

    string s;
    cin >> s;

    int tmp2 = 0;
    int a = INF;
    for (int i = 0; i + 3 < n; ++i) {
        int tmp = 0;
        if (s[i] != '2')
            tmp++;
        if (s[i + 1] != '0')
            tmp++;
        if (s[i + 2] != '2')
            tmp++;
        if (s[i + 3] != '6')
            tmp++;
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5')
            tmp2++;
        a = min(a, tmp);
    }
    
    cout << min(a, tmp2) << edl;
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