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
    int n = s.size();
    string tmp = "";
    if (s[0] == 'a') {
        int j = 0;
        int i = 0;
        for (; i < n; i++) {
            if (s[i] == 'a') {
                while (i < n && s[i] == 'a') {
                    i++;
                    tmp += 'a';
                }
                break;
            }
            tmp += s[i] - 1;
        }
        if (i < n) {
            j = i;
            while (j < n && s[j] != 'a')
                j++;
            j--;
            for (; i <= j; i++) {
                tmp += s[i] - 1;
            }
            tmp += s.substr(j + 1, n - j - 1);
        } else {
            tmp.back() = 'z';
        }

    } else {
        int j =0;
        while ( j < n &&s[j] != 'a') {
            tmp += s[j] - 1;
            j++;
        }
        tmp += s.substr(j, n - j);
    }
    cout << tmp << edl;
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