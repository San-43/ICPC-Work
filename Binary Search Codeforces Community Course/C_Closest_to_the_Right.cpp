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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(auto &e : a) cin >> e;
    while(m--) {
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        int i = n + 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(a[mid] >= x) {
                r = mid - 1;
                i = mid + 1;
            }else {
                l = mid + 1;
            }
        }
        cout << i << edl;
    }
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