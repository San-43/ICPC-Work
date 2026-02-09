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
    int n, d;
    cin >> n >> d;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ansl = 1, ansr = d;
    auto ok = [&](double const x) {
        vector<double> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (a[i] - x);
        }

        double mn = 0;
        int i = 0;
        for (int r = d; r <= n; r++) {
            int j = r - d;
            if (p[j] < mn) {
                mn = p[j];
                i = j;
            }
            if (p[r] >= mn) {
                ansl = i + 1;
                ansr = r;
                cerr << i+1 << " " << r << edl;
                return true;
            }
        }
        return false;
    };

    double l = 0.0, r = 100.0;
    for (int i = 0; i <= 80; i++) {
        double m = l + (r - l) / 2;
        if (ok(m)) l = m;
        else r = m;
    }
    ok(l);
    cout << ansl << " " << ansr << edl;
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