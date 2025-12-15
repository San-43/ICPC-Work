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

constexpr double q = 1.618033988;

void solve() {
    string s, s1;
    cin >> s >> s1;

    if (s.length() != 1) {
        if (s[0] == '1' && s[1] == '1') {
            s.insert(0, 1, '1');
            s[1] = '0';
            s[2] = '0';
        }
        if (s1[0] == '1' && s1[1] == '1') {
            s1.insert(0, 1, '1');
            s1[1] = '0';
            s1[2] = '0';
        }
        while (s.length() > s1.length())
            s1.insert(0, 1, '0');
        while (s1.length() > s.length())
            s.insert(0, 1, '0');
        for (int i = s.length() - 1; i > 2; i--) {
            if (s[i] == '1' && s[i - 1] == '1') {
                s[i - 2] = '1';
                s[i] = '0';
                s[i - 1] = '0';
            }
        }

        for (int i = s1.length() - 1; i > 2; i--) {
            if (s1[i] == '1' && s1[i - 1] == '1') {
                s1[i - 2] = '1';
                s1[i] = '0';
                s1[i - 1] = '0';
            }
        }
    }
    // cout << "s " << s << edl;
    // cout << "s1 " << s1 << edl;
    if (s < s1)
        cout << '<' << edl;
    else if (s > s1)
        cout << '>' << edl;
    else
        cout << '=' << edl;
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