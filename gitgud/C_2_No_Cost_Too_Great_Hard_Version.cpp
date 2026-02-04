#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
constexpr int dxx[8] = { 1,  1,  0, -1, -1, -1,  0,  1};
constexpr int dyy[8] = { 0,  1,  1,  1,  0, -1, -1, -1};

vector<vector<int>> p(MxN + 5);
void sieve() {
    vector<bool> ok(MxN + 5, true);
    for(int i = 2; i <= MxN; i++) {
        if(ok[i]) {
            for(int j = i; j <= MxN; j += i) {
                ok[j] = false;
                p[j].push_back(i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+5);
    vector<int> b(n+5);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int minb = INF;
    int iminb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] < minb) {
            minb = b[i];
            iminb = i;
        }
    }
    
    map<int, int> mp;
    int ans = 2;
    for (int i = 1; i <= n; i++) {
        for (auto e : p[a[i]]) {
            if (mp[e] > 0) {
                cout << 0 << edl;
                return;
            }
            mp[e]++;
        }
    }

    for(int i = 1; i <= n; i++) {
        for (auto e : p[a[i]]) mp[e]--;
        for(auto e : p[a[i] + 1]) {
            if(mp[e] > 0) ans = 1;
            
        }
        for(auto &e : p[a[i]]) mp[e]++;
    }

    cout << ans << edl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    sieve();
    while (t--) {
        solve();
    }
    return 0;
}