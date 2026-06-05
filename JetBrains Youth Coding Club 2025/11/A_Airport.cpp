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


void solve() {
    int n, m;
    cin >> n >> m;
    vi a(m);

    ll sum = 0;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    for(auto &e : a) {
        cin >> e;
        sum += e;
        pq.push(e);
        pqmin.push(e);
    }
    
    ll mx = 0;
    int i = n;
    while(!pq.empty() && i > 0) {
        int tmp = pq.top();
        pq.pop();
        i--;
        mx += tmp;
        tmp--;
        if(tmp > 0) pq.push(tmp);
    }

    ll mn = 0;
    i = n;
    while(!pqmin.empty() && i > 0) {
        int tmp = pqmin.top();
        pqmin.pop();
        i--;
        mn += tmp;
        tmp--;
        if(tmp > 0) pqmin.push(tmp);
    }

    cout << mx << " " << mn << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}