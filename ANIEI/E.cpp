#include <bits/stdc++.h>

using namespace std;
vector<bool> prime;
void sieve(long long n) { 
    vector<bool> s(n + 1, false);
    prime = s;
    for(long long p = 2; p*p <= n; p++) {
        if (!prime[p]) {
            for (long long i = p*p; i <= n; i += p) {
                prime[i] = true;
            }
        }
    }
}

void solve() {
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    sieve(1000005);
    vector<long long> pref(1000005, 0);
    for(int i = 2; i<= 1000004; i++) {
        pref[i] = pref[i - 1] + !prime[i];
    }

    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }
}