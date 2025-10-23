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
    ll n, k;
    cin >> n  >> k;
    ll ans = 0;
    ll count = 0;
    vi a(n);
    unordered_map<ll, int> m;

    for(auto &e : a) cin >> e;


    int j = 0;
    for(int i = 0; i < n; i++) {
        if(++m[a[i]] == 1) count += 1;

        while(count > k) {
            m[a[j++]]--;
            if(m[a[j]] == 0) count--;
        }

        if(count <= k) ans += i;
    }
    cout << ans-1 << edl;
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