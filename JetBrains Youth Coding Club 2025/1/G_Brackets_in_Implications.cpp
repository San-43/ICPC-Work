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
    vector<int> v(n);
    for(auto &e : v) cin >> e;

    if(v[n - 1] == 1) {
        cout << "NO" << edl;
        return;
    }

    if (n == 1) {
        cout << "YES" << edl << 0 << edl;
        return;
    } else if (n == 2) {
        if(v[0] == 1) cout << "YES\n" << 1  << "->" << 0 << edl;
        else cout << "NO\n";
        return;
    }
    
    if (v[n - 2] == 1) {
        cout << "YES" << edl;
        for(int i = 0; i < n; i++) {
            if(i != n - 1) {
                cout << v[i] << "->";
            } else {
                cout << v[i] << edl;
            }
        }
    } else if (v[n - 2] == 0 && v[n - 3] == 0) {
        cout << "YES" << edl;
        for(int i = 0; i < n - 2; i++) {
            if(i == n - 3) {
                cout << "(" << v[i] << "->" << v[i+1] << ")" << "->" << v[i + 2] << edl;
                break;
            } else {
                cout << v[i] << "->";
            }
        }
    } else {
        bool ok = false;
        int l = 0;
        for(int i = n - 3; i >= 0; i--) {
            if(v[i] == 0) {
                ok = true;
                l = i;
                break;
            }
        }

        if(!ok) {
            cout << "NO\n";
        } else {
            for(int i = 0; i < n; i++) {

                if(i == l) {
                    cout << "((" << 0 << ")" << "->" << "(";
                    while(i < n-4) {
                        cout << 1 << "->";
                        i++;
                    }
                    cout << "1))" << "->" << 0 << edl;
                    return;
                } else {
                    cout << v[i] << "->";
                }
            }
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
