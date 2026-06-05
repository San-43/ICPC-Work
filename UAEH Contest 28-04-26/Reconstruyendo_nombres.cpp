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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi a;
    for(int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());

    cout << a[3] - a[2] << ' ' << a[3] - a[1] << ' ' << a[3] - a[0] << edl;
    return 0;
}