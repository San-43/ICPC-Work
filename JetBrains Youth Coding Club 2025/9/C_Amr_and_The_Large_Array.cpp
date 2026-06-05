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
    vector<int> cub(1e6 + 5, 0);
    vi a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cub[a[i]]++;
        mx = max(cub[a[i]], mx);
    }

    map<int, vi> mp;
    ll mn = LLINF;
    for(int i = 0; i < n; i++) {
        if(cub[a[i]] == mx) {
            mp[a[i]].push_back(i+1);
        }
        if(mp[a[i]].size() == mx) {
            mn = min(mn, (mp[a[i]][mp[a[i]].size() - 1] - mp[a[i]][0] + 1));
        }
    }

    for(auto e : mp) {
        if(e.second.empty()) continue;
        if((e.second[e.second.size() - 1] - e.second[0] + 1) == mn) {
            cout << e.second[0] << " " << e.second[e.second.size() - 1] << edl;
            break;
        }
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