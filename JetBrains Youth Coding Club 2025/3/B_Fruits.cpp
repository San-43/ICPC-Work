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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    map<string, int> mp;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    vi b;
    for(auto &e : mp) {
        b.push_back(e.second);
    }
    sort(b.rbegin(), b.rend());

    ll ans1 = 0;
    ll ans2 = 0;
    for(int i = 0, j = n-1; i < sz(mp); i++, j--) {
        ans1 += a[i]*b[i];
        ans2 += a[j]*b[i];
    }
    cout << ans1 << " " << ans2 << edl;
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