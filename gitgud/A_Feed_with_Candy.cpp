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
constexpr int dxx[8] = { 1,  1,  0, -1, -1, -1,  0,  1};
constexpr int dyy[8] = { 0,  1,  1,  1,  0, -1, -1, -1};

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;
    for(int i = 0; i < n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        if(t == 0) {
            a.emplace_back(h, m);
        } else b.emplace_back(h, m);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans1 = 0;
    int ans2 = 0;
    int l = 0;
    int r = 0;
    bool tmp = false;
    int xx = x;
    priority_queue<int> qa, qb;
    while (true) {
        if(!tmp) {
            while(l < sz(a) && a[l].first <= x) qa.push(a[l++].second); 
            if(qa.empty()) break;
            x += qa.top();
            qa.pop();
            ans1++;
            tmp = true;
        } else {
            while(r < sz(b) && b[r].first <= x) qb.push(b[r++].second);
            if(qb.empty()) break;
            x += qb.top();
            qb.pop();
            ans1++;
            tmp = false;
        }
    }
    tmp = true;
    l = 0;
    r = 0;
    x = xx;
    while (!qa.empty()) {qa.pop();}
    while (!qb.empty()) {qb.pop();}
    while (true) {
        if(!tmp) {
            while(l < sz(a) && a[l].first <= x) qa.push(a[l++].second);
            if(qa.empty()) break;
            x += qa.top();
            qa.pop();
            ans2++;
            tmp = true;
        } else {
            while(r < sz(b) && b[r].first <= x) qb.push(b[r++].second);
            if(qb.empty()) break;
            x += qb.top();
            qb.pop();
            ans2++;
            tmp = false;
        }
    }
    cout << max(ans1, ans2) << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}