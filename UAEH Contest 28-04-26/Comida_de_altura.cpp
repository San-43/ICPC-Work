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


int main() {
    vector<vector<ll>> a(20000, vector<ll>(7, 0));

    ll tmp = 0;
    int cont = 0;
    for(int i = 0; i < 1030; i++) {
        if(cont == 2) {
            tmp += 2;
            i += 2;
            cont = 0;
        }
        a[i][0] = tmp + 4;
        a[i][1] = tmp + 5;
        a[i][2] = tmp + 6;
        a[i][3] = tmp + 3;
        a[i][4] = tmp + 2;
        a[i][5] = tmp + 1;
        if(i + 2 < 1018) {
            a[i+2][0] = tmp + 4;
            a[i+2][1] = tmp + 5;
            a[i+2][2] = tmp + 6;
            a[i+2][3] = tmp + 3;
            a[i+2][4] = tmp + 2;
            a[i+2][5] = tmp + 1;
        }
        cont++;
        tmp += 7;
    }
    int x;
    cin >> x;
    string c; cin >> c;
    int j = c.back() - 'a';

    if(x == 0) {
        cout << 0 << edl;
        return 0 ;
    }
    
    cout << a[x-1][j] << edl;
    return 0;
}