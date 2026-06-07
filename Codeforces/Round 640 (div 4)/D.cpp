#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    int l = 1;
    int r = n - 1;
    int tmp = a[0];
    int aa = tmp;
    int bb = 0;
    int mv = 1;

    bool bob = true;

    while(l <= r) {
        int sm = 0;
        while(sm <= tmp && l <= r) {
            if(bob) {
                sm += a[r];
                bb += a[r];
                r--;
            } else {
                sm += a[l];
                aa += a[l];
                l++;
            }
        } 
        mv++;
        tmp = sm;
        bob = !bob;
    }

    cout << mv << " " << aa << " " << bb << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}