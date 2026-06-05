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

void solve() {
    int n, x, k;
    cin >> n >> k >> x;
    vi arr(n);
    vi arr2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        arr2[i + 1] = arr[i] + arr2[i];
    }
    int ans = -INF;
    for (int i = 0 ; i <= k && i <= n; i++) {
        int total = arr2[max(n - i - x, 0)] - (arr2[n - i] - arr2[max(n - i - x, 0)]);
        ans = max(ans, total);
    }
    cout << ans << edl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}