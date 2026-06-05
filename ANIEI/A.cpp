#include <bits/stdc++.h>

using namespace std;
vector<bool> prime;
void sieve(int n) { 
    vector<bool> s(n + 1, false);
    prime = s;
    for(long long p = 2; p*p <= n; p++) {
        if(prime[p] == false) {
            for(long long i = p*p; i <= n;i += p)
                prime[i] = true;
        }
    }
}

void solve() {
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(3);
    cin >> a[0];
    cin >> a[1] >> a[2];

    int ans = 0;
    for(int i= 0; i< (1 << 3); i++) {
        int sum = 0;
        int tmp = 0;
        for(int j = 0; j < 3; j++) {
            if(i & (1 << j)) {
                sum += a[j];
            } else {
                if(a[j] >= 500) {
                    tmp += 100;
                }
            }
        }
        if(sum >= 500) tmp +=100;
        ans = max(ans, tmp);
    }
    cout << (a[0] +a[1] +a[2] - ans) << '\n';
}