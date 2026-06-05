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
constexpr int dxx[8] = { 1,  1,  0, -1, -1, -1,  0,  1};
constexpr int dyy[8] = { 0,  1,  1,  1,  0, -1, -1, -1};


void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<pair<ll, int>> a;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.emplace_back(x, i);
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while(l < r) {
        ll sum = a[l].first + a[r].first;
        if(sum < k) l++;
        else if(sum > k) r--;
        else {
            cout << a[l].second + 1 << " " << a[r].second + 1 << edl;
            break;
        }
    }
    if (l == r) cout << "IMPOSSIBLE" << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}