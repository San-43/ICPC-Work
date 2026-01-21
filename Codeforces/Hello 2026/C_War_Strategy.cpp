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
    ll n, k, m;
    cin >> n >> m >> k;
    m++;
    ll x = k - 1;
    ll y = n - k;
    
    if(x > y) swap(x, y);
    if(x + y + y <= m) cout << x + y + 1 << edl;
    else if(3 * x <= m) cout << x + (m - x) / 2 + 1 << edl;
    else {
        cout << (2 * m / 3) + 1 << edl;
    }
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