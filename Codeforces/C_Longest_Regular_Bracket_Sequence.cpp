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

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    vector<int> ans(s.length(), -1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            if (st.empty()) {
                ans[i] = -1;
                continue;
            }
            ans[i] = st.top();
            st.pop();
            if (ans[i] - 1 >= 0) {
                if (ans[ans[i] - 1] != -1) {
                    ans[i] = ans[ans[i] - 1];
                }
            }
        } else
            st.push(i);
    }

    ll count = 1;
    ll l = 0;
    for(int i = 0; i < s.length(); i++) {
        if(ans[i] != -1) {
            ll tmp = i - ans[i] + 1;
            if(tmp > l) {
                l = tmp;
                count = 1;
            } else if(tmp == l) {
                count++;
            }
        }
    }

    cout << l << " " << count << edl;
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