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

    if (n == 1) {
        cout << "YES" << '\n';
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        if (r == n - 1) {
            if (a[i-1] > a[i]) count++;
            break;
        }
        if (i == 0) {
            while (r < n && a[r] == a[i]) r++;
            if (r == n) count++;
            else if (a[r] > a[r - 1]) {
                count++;
            }
        } else {
            if (a[i-1] > a[i]) {
                while (r < n && a[r] == a[i]) r++;
                if (r == n) count++;
                else if (a[r] > a[r - 1]) {
                    count++;
                }
            }
        }
    }

    cout << (count == 1 ? "YES" : "NO") << '\n';
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