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
    int l, r;
    int m = 0; 
    int c = INF;
    for(int i = 0; i < n; i++)
        {   
            int x; 
            cin >> x;
            if(m < x) 
                l = i;
            if(c > x)
                r = i;
            m = max(m, x);
            c = min(c, x);
        }
    
    int ans = 0;
    ans = max(abs(0 - l), abs(n - l - 1));
    ans = max(ans, abs(0 - r));
    ans = max(ans, abs(n - 1 - r ));
    cout << ans << edl;
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