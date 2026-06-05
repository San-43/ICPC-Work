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
    if( n < 4) {
        cout << -1 << edl;
        return;
    }

    int r = n % 4;
    if(r == 0 || r == 2) {
        cout << n / 4 << edl;
        return;
    }
    if(r == 1) {
        if(n >= 9) cout << (n / 4 - 1) << edl;
        else cout << -1 << edl;
    } else if (r == 3) {
        if(n >= 15) cout << (n / 4 - 1) << edl;
        else cout << -1 << edl;
    }
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