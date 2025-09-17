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

struct p
{   
    int x;
    int y;
};

int distance(p p1, p p2) {
    return static_cast<int>(sqrt((pow((p1.x - p2.x), 2)) + pow((p1.y - p2.y), 2)));
}

void solve() {
    int n;
    cin >> n;
    vector<p> v(n);
    while(n--) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x,y);
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