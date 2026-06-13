//
// Created by san43 on 6/8/26.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> a(3);
    
    for (int i =0 ; i < 3; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << a[1] << '\n';
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