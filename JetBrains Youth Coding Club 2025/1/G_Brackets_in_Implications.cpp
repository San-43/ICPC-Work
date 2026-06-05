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
    for (auto &e : v)
        cin >> e;

    if (v[n - 1] == 1) {
        cout << "NO" << edl;
        return;
    }

    if (n == 1) {
        cout << "YES" << edl;
        cout << 0 << edl;
        return;
    }

    if (v[n - 2] == 1) {
        cout << "YES" << edl;
        for (int i = 0; i < n; i++) {
            cout << v[i];
            if (i < n - 1)
                cout << "->";
        }
        cout << edl;
        return;
    }

    if(n >= 3 && v[n - 3] == 0) {
        cout << "YES" << edl;
        for(int i = 0; i < n; i++) {
            if(i == n - 3) cout << "(";
            cout << v[i];
            if(i == n - 2) cout << ")";
            if(i < n - 1) cout << "->";
        }
        cout << edl;
        return;
    }

    int l = n - 3;
    while(l >= 0 && v[l] == 1) l--;

    if (l < 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES" << edl;
    for (int i = 0; i < n; i++) {
        if(i == l) cout << "(";
        if(i == l + 1) cout << "((";
        cout << v[i];
        if(i == n - 3) cout << ")";
        if(i == n - 2) cout << "))";
        if(i < n - 1) cout << "->";
    }
    cout << edl;
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
