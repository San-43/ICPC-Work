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

struct p {
    int t;
    int y;
    int z;
    int k;
};

void solve() {
    int m, n;
    cin >> m >> n;
    vector<p> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].z >> a[i].y;
        a[i].k = a[i].t*a[i].z + a[i].y;
    }
    if(m == 0) {
        cout << 0 << edl;
        for(int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        return;
    }

    auto ok = [&](ll mid) {
        ll sm = 0;
        for(int i = 0; i < n; i++) {
            ll tmp = mid / a[i].k;
            ll r = mid % a[i].k;
            sm += tmp*a[i].z + min((ll)a[i].z, r / a[i].t);
        }

        return sm >= m;
    };

    ll l = 0;
    ll r = 1;
    while(!ok(r)) r *= 2;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(ok(mid)) r = mid;
        else l = mid; 
    }
    cout << r << edl;

    for(auto &e : a) {
        ll tmp = r / e.k;
        ll rest = r % e.k;
        ll ans = tmp * e.z + min((ll)e.z, rest / e.t);
        if(ans < m) {
            cout << ans << " ";
            m -= ans;
        } else if(ans >= m && m != 0) {
            cout << m << " ";
            m = 0;
        } else {
            cout << 0 << " ";
        }
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