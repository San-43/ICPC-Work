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
    int k;
    cin >> k;

    unordered_map<string, int> ones;   
    unordered_set<string> twos;       
    int total = n;

    for (int i = 0; i < k; i++) {
        int x, y;
        string s, s1;
        cin >> x >> y >> s >> s1;

        if (s == s1) {
            if (twos.count(s)) {
                twos.erase(s);
            } else if (ones.count(s)) {
                ones.erase(s);
                total -= 1;
            } else {
                total -= 2; 
            }
        } else {
            if (ones.count(s)) {
                if (ones[s] != x) {
                    ones.erase(s);
                    twos.insert(s);
                    total -= 1; 
                }
            } else if (!twos.count(s)) {
                ones[s] = x;
                total -= 1;
            }

            if (ones.count(s1)) {
                if (ones[s1] != y) {
                    ones.erase(s1);
                    twos.insert(s1);
                    total -= 1;
                }
            } else if (!twos.count(s1)) {
                ones[s1] = y;
                total -= 1;
            }
        }
    }

    int ans = (int)twos.size();
    if (total == 2 && ones.empty()) {
        ans += 1;
    } else if (total == (int)ones.size()) {
        ans += total;
    }

    cout << ans << '\n';
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
