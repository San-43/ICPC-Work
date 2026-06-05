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

struct p
{
    ll x;
    ll y;
};

void solve() {
    int n;
    cin >> n;
    vector<p> v;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    vi d(n);
    for (int i = 1; i < n; i++) {
        d[i] = llabs(v[i-1].x - v[i].x) + llabs(v[i-1].y - v[i].y);
    }

    ll c = 0;
    ll lb = -LLINF;
    ll ub = LLINF;

    for(int i = 1; i < n; i++) {
        
        if(i & 1) {
            lb = max(lb, 1 - c);
        } else {
            ub = min(ub, c - 1);
        }

        if(i & 1) {
            ub = min(ub, d[i] - 1 - c);
        } else {
            lb = max(lb, c - d[i] + 1);
        }

        c = d[i] - c;
    }

    if (n & 1) lb = max(lb, 1 - c);
    else ub = min(ub, c - 1);

    if(lb <= ub) {
        cout << ub << edl;
    } else {
        cout << -1 << edl;
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