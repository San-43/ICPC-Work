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
    cin >> n;
    map<ll, set<int>> mp;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].insert(i);
    }

    while(!mp.empty()) {
        auto [fst, snd] = *mp.begin();
        while (sz(snd) >= 2) {
            int i = *snd.begin();
            snd.erase(snd.begin());
            int j = *snd.begin();
            snd.erase(snd.begin());
            a[i] = 0;
            a[j] = 2*fst;
            mp[2*fst].insert(j);
        }
        mp.erase(mp.begin());
    }

    vi ans;
    for (const auto i : a) {
        if (i > 0) ans.pb(i);
    }

    cout << sz(ans) << edl;
    for (const auto i : ans) cout << i << ' ';
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