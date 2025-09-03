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

    set<string> l;

    map<char, int> m;
    m['H'] = 0;
    m['P'] = 0;
    m['T'] = 0;
    m['K'] = 0;
    
    for (size_t i = 0; i <= s.length() - 3; i+=3) {
        string t = s.substr(i, 3);
        if(l.count(t)) {
            cout << "GRESKA" << '\n';
            return;
        } 
        l.insert(t);
        m[t[0]]++;
    }
    
    cout << 13 - m['P'] << " " << 13 - m['K'] << " " << 13 - m['H'] << " " << 13 - m['T'] << '\n';
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