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
    int n;
    cin >> n;
    vi a(n);
    for (auto &e : a) cin >> e;
    vi b(n);
    for (auto &e : b) cin >> e;

    auto c = a;
    sort(c.begin(), c.end());

    vector<pair<int, int>> ans;

    if (!is_sorted(a.begin(), a.end()))
    {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (c[i] == a[j])
                {
                    swap(a[j], a[i]);
                    swap(b[j], b[i]);
                    ans.emplace_back(j+1, i+1);
                    break;
                }
            }
        }
    }
    if (is_sorted(b.begin(), b.end()))
    {
        cout << ans.size() << edl;
        for (auto e : ans)
        {
            cout << e.first << ' ' << e.second << edl;
        }
    } else
    {
        for (int i = 0; i < a.size() - 1; i++)
        {
            int j = i;
            while (i < a.size() - 1 && a[i] == a[i+1])
            {
                i++;
            }
            if (!is_sorted(b.begin() + j, b. begin() + i + 1))
            {
                vector<int> tmp(b.begin() + j, b.begin() + i + 1);
                sort(tmp.begin(), tmp.end());
                for (int k = 0; k < i - j + 1; k++)
                {
                    for (int l = k + j + 1; l < i+1; l++)
                    {
                        if (b[j + k] == tmp[k]) continue;
                        if (tmp[k] == b[l])
                        {
                            ans.emplace_back(l + 1, j + k + 1);
                            swap(b[k + j], b[l]);
                            break;
                        }
                    }
                }
            }
        }
        if (is_sorted(b.begin(), b.end()))
        {
            cout << ans.size() << edl;
            for (auto e : ans)
            {
                cout << e.first << ' ' << e.second << edl;
            }
            return;
        }
        cout << -1 << edl;
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