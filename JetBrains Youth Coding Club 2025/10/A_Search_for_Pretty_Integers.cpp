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
    set<int> s;
    int mn = INF;
    int ma = INF;
    int mb = INF;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        ma = min(ma, x);
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if(s.contains(x)) {
            mn = min(mn, x);
        }
        mb = min(mb, x);
    }
    if(mn != INF) {
        cout << mn << edl;
    } else {
        if (ma > mb) swap(ma, mb);
        cout << (ma*10 + mb) << edl;
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