//
// Created by san43 on 6/8/26.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    cout << s[n - 1] - 'a' + 1 << '\n';
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