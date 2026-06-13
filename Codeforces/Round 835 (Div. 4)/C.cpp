//
// Created by san43 on 6/8/26.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    auto b = a;
    sort(b.begin(), b.end());

    int mx = b[n - 1];
    int mmx = b[n - 2];
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            cout << mx - mmx << ' ';
        } else {
            cout << a[i] - mx << ' ';
        }
    }
    cout << '\n';
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}