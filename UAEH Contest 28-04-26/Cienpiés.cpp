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

void solve() {
    int n, m;
    cin >> n >> m;
    bool bn = true;
    string s = "";
    string s1 = "";
    for(int i = 0; i < m; i++) {
        s += '#';
    }
    for(int i = 1; i < m; i++) {
        s1 += '.';
    }

    for(int i = 0 ; i < n; i++) {
        if(i % 2 == 0) {
            cout << s << edl;
        } else {
            if(bn) {
                cout << s1 << '#' << edl;
            } else {
                cout << '#' << s1 << edl;
            }
            bn = !bn;
        }

    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}