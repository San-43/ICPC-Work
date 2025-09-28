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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int s = sqrt(n);
    vector<int> b(n);
    for(int i = 0; i < n; i += s) {
        b[i / s] = *max_element(v.begin() + i, v.begin() + i + s);
    }

    int ans = 0;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int tmp = l;
        tmp--;
        r--;
        int val = INT_MIN;
        while(tmp < r) {
            if(tmp % s == 0 && tmp + s <= r) {
                val = max(val, b[tmp / s]);
                tmp += s;
            } else {
                val = max(val, v[tmp++]);
            }
        }
        if(val <= v[l-1]) ans++;
    }
    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}