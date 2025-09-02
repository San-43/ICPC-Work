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

int ans(int n, bool out) {
    vector<int> deck(n);
    iota(deck.begin(), deck.end(), 1);
    vector<int> original = deck;
    int count = 0;

    do {
        vector<int> left, right, next;
        if (out) {
            int mid = (n + 1) / 2;
            left.assign(deck.begin(), deck.begin() + mid);
            right.assign(deck.begin() + mid, deck.end());
            for (int i = 0; i < (int)left.size(); i++) {
                next.push_back(left[i]);
                if (i < (int)right.size()) next.push_back(right[i]);
            }
        } else {
            int mid = n / 2;
            left.assign(deck.begin(), deck.begin() + mid);
            right.assign(deck.begin() + mid, deck.end());
            for (int i = 0; i < (int)right.size(); i++) {
                next.push_back(right[i]);
                if (i < (int)left.size()) next.push_back(left[i]);
            }
        }
        deck = next;
        count++;
    } while (deck != original);

    return count;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    bool out = (s == "out");
    cout << ans(n, out) << "\n";
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