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

ll maxSubarraySum(const vi &arr) {
    ll maxSum = INF * -1, currentSum = 0;
    for (ll num : arr) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int p = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p = i;
            a[i] = -INF;
        }
    }

    ll mx = maxSubarraySum(a);
    if (mx > k || (mx != k && p == -1)){
        cout << "NO" << edl;
        return;
    }
    else if (p != -1) {
        mx = 0;
        ll current = 0;
        ll tmp = -INF;
        ll l, r;
        for (int i = p + 1; i < n; i++) {
            current += a[i];
            tmp = max(current, tmp);
        }
        l = mx;

        mx = 0;
        current = 0;
        tmp = -INF;

        for (int i = p - 1; i >= 0; i--) {
            current += a[i];
            tmp = max(current, tmp);
        }

        r = mx;
        a[p] = k - l - r;
    }

    cout << "YES" << edl;
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            cout << a[i] << " ";
        else
            cout << a[i] << edl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}