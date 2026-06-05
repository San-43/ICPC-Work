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
    char a, b, c, d;
    cin >> a >> b >> c >> d;

    pair<int, int> l = {(a - 'A' + 1), (b - '0')};
    pair<int, int> r = {(c - 'A' + 1), (d - '0')};

    if ((l.first + l.second) % 2 != (r.first + r.second) % 2) {
        cout << "Impossible\n";
        return;
    }

    if (l.first == r.first && l.second == r.second) {
        cout << 0 << " " << a << " " << b << '\n';
        return;
    }

    if (abs(l.first - r.first) == abs(l.second - r.second)) {
        cout << 1 << ' ' << a << " " << b << " " << c << " " << d << '\n';
        return;
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (abs(i - l.first) == abs(j - l.second) &&
                abs(i - r.first) == abs(j - r.second)) {
                cout << 2 << ' ' << a << " " << b << " "
                     << char('A' + i - 1) << " " << j << " "
                     << c << " " << d << '\n';
                return;
            }
        }
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