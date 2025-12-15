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
    string t, p;
    cin >> t >> p;
    vector<int> a((int) t.size());
    for(auto &e : a) cin >> e;

    vector<int> cub((int) t.length() + 5);
    for(int i = 1; i <= t.length(); i++) {
        cub[a[i - 1]] = i;
    }


    auto ok = [&](int mid) {
        auto tmp = t;
        int l = 0;
        int r = 0;
        while(l < p.length() && r < t.length()) {
            if(cub[r+1] > mid && tmp[r] == p[l]) l++;
            r++;
        }
        if(l < p.length()) return false;
        return true;
    };

    int l = 0;
    int r = (int) t.size();

    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    cout << l << edl;
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