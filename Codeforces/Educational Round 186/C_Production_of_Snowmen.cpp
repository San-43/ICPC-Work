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
    ll n;
    cin >> n;
    vi a(n), b(n), c(n);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    for (auto &e : c) cin >> e;

    ll ab = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[j] >= b[(i + j) % n]) {
                ok = false;
                break;
            }
        }
        if(ok) ab++;
    }

    ll bc = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (b[j] >= c[(i + j) % n]) {
                ok = false;
                break;
            }
        }
        if(ok) bc++;
    }
    
    cout << n*ab*bc << edl;
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