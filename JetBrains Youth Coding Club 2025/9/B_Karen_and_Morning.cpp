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

bool pal(string &s) {
    int l = 0;
    int r = s.length() - 1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    if(pal(s)) {
        cout << 0 << edl;
    } else {
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3, 2));

        int ans = 0;
        while (!pal(s)) {
            mm++;
            if (mm == 60) {
                mm = 0;
                hh = (hh + 1) % 24;
            }

            string h = to_string(hh);
            if (hh < 10) h = "0" + h;
            string m = to_string(mm);
            if (mm < 10) m = "0" + m;
            s = h + ":" + m;

            ans++;
        }
        cout << ans << edl;
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