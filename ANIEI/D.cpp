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
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int count = 0;
        int tmp = n;
        while(tmp >= 10) {
            int mul = 1;
            n = tmp;
            while(n > 0) {
                mul *= n%10;
                n /= 10;
            }
            tmp = mul;
            count++;
        }
        cout << count << '\n';
    }
}