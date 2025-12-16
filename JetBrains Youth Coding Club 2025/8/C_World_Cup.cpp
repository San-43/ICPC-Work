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
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);

    int total = 0;
    while(n > 1) {
        n /= 2;
        total++;
    }
    
    int ans = 1;
    while(((a - 1) / 2) != ((b - 1) / 2)) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ans++;
    }
    ans == total ? cout << "Final!" << edl : cout << ans << edl;
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