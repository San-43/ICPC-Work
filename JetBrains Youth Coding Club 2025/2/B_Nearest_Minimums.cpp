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

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = make_pair(x, i);
    }

    sort(v.begin(), v.end());
    int m = v[0].first;
    int j = 0;
    int ans = INF;
    while(m == v[j].first) {
        int tmp = 0;
        if( j+ 1 < n && v[j+1].first == m) tmp = v[j+1].second;
        ans = min(ans, abs(v[j].second - tmp));
        j++;
    }

    cout << ans << edl;
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