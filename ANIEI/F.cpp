#include <bits/stdc++.h>

using namespace std;

const int dr[8] = {1,-1,0,0,1,1,-1,-1};
const int dc[8] = {0,0,1,-1,1,-1,1,-1};

int n, m;

int ans = -1e9;

bool ok(int rw, int cl) {return 0 <= rw && rw<n && 0 <= cl && cl < m;}

void dfs(int r, int c, string &s, vector<vector<char>> &v) {
        if(!ok(r, c)) return;
        if(s[s.size() - 1] + 1 != v[r][c]) return;

        s += v[r][c];
        ans = max(ans, (int) s.size());
        for(int i = 0; i < 8; i++) {
            int rc = dr[i] + r;
            int cl = dc[i] + c;
            dfs(rc, cl, s, v);
        }

        s.pop_back();
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i< n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            string s = "";
            s += v[i][j] - 1;
            dfs(i, j, s, v);
        }
    }

    cout << ans - 1 << '\n';
}