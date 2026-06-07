#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k < n) {
            cout << k << '\n';
        } else if (k == n) cout << k + 1 << '\n';
        else {
            int tmp = (k - 1) / (n - 1);
            long long ans = k + tmp;
            cout << ans << '\n';
        }
    }
}