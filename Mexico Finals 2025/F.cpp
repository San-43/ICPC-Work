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

int prime[1000005];
vector<int> primes;

void sieve(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(prime[i] == 0) {
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;
    map<int, int> mp;
    sieve(100000);
    string tmp;
    for (int i = 0; i < min(sz(s), 10); i++) {
        tmp += s[i];
    }
    int ans = stoi(tmp);

    if (sz(s) > 10) {
        mp[2] = sz(s) - 10;
        mp[5] = sz(s) - 10;
    }
    for (auto i : primes) {
        while (ans % i == 0 && ans > 1) {
            ans /= i;
            mp[i]++;
        }
    }

    if (sz(mp) > 0) {
        cout << sz(mp) << endl;
        for (auto i : mp) {
            cout << i.first << ' ' << i.second << endl;
        }
    } else {
        cout << 1 << edl;
        cout << ans << " " <<  1 << endl;
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