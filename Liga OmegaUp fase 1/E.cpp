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

static bool isNumber(const string &s) {
    if (s.empty())
        return false;
    int i = 0;
    if (s[0] == '-') {
        if ((int)s.size() == 1)
            return false;
        i = 1;
    }
    for (; i < (int)s.size(); ++i)
        if (!isdigit((unsigned char)s[i]))
            return false;
    return true;
}



void solve() {
    string s;
    vector<string> a;
    while (cin >> s)
        a.push_back(s);
    stack<ll> st;
    for (int i = a.size() - 1; i >= 0; i--) {
        string c = a[i];
        if (isNumber(c)) {
            st.push(stoll(c));
        } else {
            ll a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if (c == "+") st.push(a + b);
            else if (c == "-") st.push(a - b);
            else if (c == "*") st.push(a * b);
            else if (c == "/") st.push(a / b);
            else if (c == "e") st.push(pow(a, b));
        }
    }

    cout << st.top() << edl;
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