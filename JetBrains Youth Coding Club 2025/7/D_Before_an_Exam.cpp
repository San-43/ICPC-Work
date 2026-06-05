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
    int d, t;
    cin >> d >> t;
    vector<pair<int,int>> a;
    int mn = 0;
    int mx = 0;
    vector<int> ans;
    for(int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
        mn += x;
        mx += y;
        ans.push_back(x);
    }
    if(t >= mn && t <= mx) {
        cout << "YES" << edl;
        int i = 0;
        int r = t - mn;
        while(true) {
            if(i == ans.size()) i = 0;
            if(r <= 0) {
                break;
            }
            int tmp = a[i].second - a[i].first;
            
            int z = min(tmp, r);
            ans[i] += z;
            r -= z;
            i++;
        }

        for(auto &e : ans) cout << e << " ";
    } else {
        cout << "NO" << edl;
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