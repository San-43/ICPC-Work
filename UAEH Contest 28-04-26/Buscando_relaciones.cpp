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

void solve() {

    int n;
    cin >> n;
    vi a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;

    if(a == b) {
        cout << "YES" << edl;
        return;
    } else {
        vi ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = b[i] - a[i];
        }
        bool no = ans.end() != find_if(ans.begin(), ans.end(), [](const int& x) {
            return x < 0;
        });
        if (no) {
            cout << "NO" << edl;
            return;
        }
        bool ok = false;
        for(int i = 0 ; i < n; i++) {
            if(ans[i] != 0 && ok) {
                cout << "NO" << edl;
                return;
            }
            if (ans[i] != 0) {
                ok = true;
                int tmp = ans[i];
                while(ans[i] != 0 && i < n) {
                    if(ans[i] != tmp) {
                        cout << "NO" << edl;
                        return;
                    }
                    if(ans[i] == 0) break;
                    i++;
                }
            }
        }
        cout << "YES" << edl;

        // vi com;
        // com.push_back(ans[0]);
        // for (int i = 1; i < n; i++) {
        //     if (com.back() != ans[i] ) {
        //         com.push_back(ans[i]);
        //     }
        // }
        // if (sz(com) > 3) {
        //     cout << "NO" << edl;
        //     return;
        // }
        // vi real;
        // for (auto i : com) {
        //     if (i) {
        //         real.push_back(i);
        //     }
        // }
        // cout << (sz(real) == 1 ? "YES" : "NO") << edl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}