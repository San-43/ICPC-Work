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
    int n, k;
    cin >> n >> k;
    vector a(n, vector<int>(n));

    int x = n*n;
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= k - 1; j--) {
            a[i][j] = x--;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = k - 2; j >= 0; j--) {
            a[i][j] = x--;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i][k - 1];
    }
    cout << sum << edl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << edl;
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