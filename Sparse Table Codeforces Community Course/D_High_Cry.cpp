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

    vector<int> lg(n + 1, 0);
    for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;

    int LG = lg[n] + 1;

    vector<vector<ll>> stmax(LG, vector<ll>(n));
    vector<vector<ll>> stor(LG, vector<ll>(n));

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stmax[0][i] = x;
        stor[0][i] = x;
    }

    for(int k = 1; k < LG; k++) {
        for(int i = 0; i + (1 << k) <= n; i++) {
            stmax[k][i] = max(stmax[k - 1][i], stmax[k - 1][i + (1 << (k - 1))]);
            stor[k][i] = stor[k - 1][i] | stor[k - 1][i + (1 << (k - 1))];
        }
    }

    auto m = [&](int l, int r) {
        int k = lg[r - l];
        return max(stmax[k][l], stmax[k][r - (1 << k)]);
    };

    auto qor = [&](int l, int r) {
        int k = lg[r - l];
        return stor[k][l] | stor[k][r - (1 << k)];
    };

    ll ans = 0;
    for(int l = 0; l < n; l++) {
        int r = l;
        while (r < n) {
            const int v = qor(l, r + 1);

            int lo = r;
            int hi = n - 1;
            int rend = r;
            while(lo <= hi) {
                int mid = (hi + lo) >> 1;
                if(qor(l, mid + 1) == v) {
                    rend = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }

            lo = r;
            hi = rend;
            int p = rend + 1;
            while (lo <= hi) {
                int mid = (hi + lo) >> 1;
                if(m(l, mid + 1) >= v) {
                    p = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }

            if (p > rend) {
                ans += (rend - r + 1);
            } else {
                ans += max(0, p - r); 
            }

            r = rend + 1;
        }
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