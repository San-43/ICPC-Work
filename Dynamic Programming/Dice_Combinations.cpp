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

using int64 = ll;

inline int64 norm(int64 x){ x%=MOD; if(x<0) x+=MOD; return x; }
inline int64 addm(int64 a,int64 b){ a+=b; if(a>=MOD) a-=MOD; return a; }
inline int64 subm(int64 a,int64 b){ a-=b; if(a<0) a+=MOD; return a; }
inline int64 mulm(int64 a,int64 b){ return (int64)((__int128)a * b % MOD); }

void solve() {
    int n;
    cin >> n;

    vi dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                dp[i] = addm(dp[i], norm(dp[i - j]));
            } 
        }
    }

    cout << dp[n] << edl;
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