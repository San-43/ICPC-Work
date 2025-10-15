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
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
    }

    vi ans(n + 1);
    vi stack;
    for(int i = 1; i <= n; i++) {
        while(!stack.empty() && a[stack.back()] >= a[i]) stack.pop_back();
        ans[i] = stack.empty() ? 0 : stack.back();
        stack.push_back(i);
    }

    for(int i =1; i<= n; i++) {
        if(i > 1) cout << " ";
        cout << ans[i];
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