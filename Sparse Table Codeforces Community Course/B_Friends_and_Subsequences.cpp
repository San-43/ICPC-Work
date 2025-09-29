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
    vector<vector<int>> spmin(20, vector<int>(n + 1));
    vector<vector<int>> spmax(20, vector<int>(n + 1));

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> spmin[0][i];
    }
    for(int i = 0; i < n; i++) {
        cin >> spmax[0][i];
    }

    vector<int> lg(n + 1, 0);
    for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;

    ll LG = lg[n] + 1;

    for(int k = 1; k < LG; k++)
        for(int i = 0; i + (1 << k) <= n; i++) {
            spmin[k][i] = min(spmin[k - 1][i], spmin[k - 1][i + (1 << (k - 1))]);
            spmax[k][i] = max(spmax[k - 1][i], spmax[k - 1][i + (1 << (k - 1))]);
        }
    
    auto maxl = [&](int l, int r) {
        int k = lg[r - l];
        return max(spmax[k][l], spmax[k][r - (1 << k)]);
    };

    auto minl = [&](int l, int r) {
        int k = lg[r - l];
        return min(spmin[k][l], spmin[k][r - (1 << k)]);
    };

    auto h = [&](int l, int r) {
        return maxl(l, r) - minl(l, r);
    };
    
    for(int i = 0; i < n; i++) {
        int l = i; int r = n - 1;

        int limit1 = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if(h(l, mid) >= 0) {
                r = mid - 1;
                limit1 = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if(h(l, limit1) > 0 || limit1 == -1) continue;

        l = limit1; r = n - 1;
        int limit2 = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(h(l, mid) > 0) {
                limit2 = mid;
                r = mid - 1;
            } else 
                l = mid + 1;
        }

        ans += limit2 - limit1;
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