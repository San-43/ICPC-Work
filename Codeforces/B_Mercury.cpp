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
    string s;
    cin >> s;
    set<string> list;
    for(int i = 1; i <= 25; i++) {
        string ans = "";
        for(auto c : s) {
            int x = c - 'a';
            int y = (x + i) % 26;
            ans += y + 'a';
        }
        list.insert(ans);
    }

    int n;
    cin >> n;
    vector<string> v;
    while(n--) {
        string tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for(auto c : list) {
        bool can = true;
        for (auto c1 : v) {
            if (c.find(c1) == string::npos) {
                can = false;
            }
        }
        if (can) {
            cout << c << edl;
            return;
        }
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