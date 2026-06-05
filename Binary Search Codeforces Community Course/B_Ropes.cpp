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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for(auto &e : a) {
        cin >> e;
    }


    auto f = [&](double x) {
        ll sum = 0.0;
        for(int i = 0; i < n; i++) {
            sum += floor(a[i] / x);
        }
        return sum >= k;
    };

    double l = 0.0, r = 1e8;
    
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(20) << l << edl;

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