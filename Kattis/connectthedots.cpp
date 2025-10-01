#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
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

template <typename T>
void fill_seq(vector<T> &v, T start = 1) { iota(v.begin(), v.end(), start); }

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

static inline char getSymbol(int index) {
    if (index <= 9) return char('0' + index);
    index -= 10;
    if (index <= 25) return char('a' + index);
    index -= 26;
    return char('A' + index);
}

static void connect_segment(vector<string>& img, pair<int,int> a, pair<int,int> b) {
    // vertical
    if (a.se == b.se) {
        int c = a.se;
        int lo = min(a.fi, b.fi), hi = max(a.fi, b.fi);
        for (int r = lo + 1; r < hi; ++r) {
            char &cell = img[r][c];
            if (cell == '.') cell = '|';
            else if (cell == '-') cell = '+';
        }
    } else { // horizontal
        int r = a.fi;
        int lo = min(a.se, b.se), hi = max(a.se, b.se);
        for (int c = lo + 1; c < hi; ++c) {
            char &cell = img[r][c];
            if (cell == '.') cell = '-';
            else if (cell == '|') cell = '+';
        }
    }
}

static void connectDots(vector<string>& img, unordered_map<char, pair<int,int>>& pos) {
    int idx = 0;
    while (true) {
        char s1 = getSymbol(idx);
        if (!pos.count(s1)) break;
        auto p1 = pos[s1];

        ++idx;
        char s2 = getSymbol(idx);
        if (!pos.count(s2)) break;
        auto p2 = pos[s2];

        connect_segment(img, p1, p2);
    }
}

static void printImage(const vector<string>& img, int imageId) {
    if (imageId > 0) cout << '\n';
    for (const auto& row : img) cout << row << '\n';
}

void solve() {
    vector<string> image;
    unordered_map<char, pair<int,int>> symbolsMap;
    int rowNumber = 0;
    int imageId = 0;

    string line;
    while (true) {
        if (!getline(cin, line)) {
            if (!image.empty()) {
                connectDots(image, symbolsMap);
                printImage(image, imageId);
            }
            break;
        }
        if (!line.empty() && line.back() == '\r') line.pop_back(); // handle CRLF

        if (line.empty()) {
            connectDots(image, symbolsMap);
            printImage(image, imageId);

            image.clear();
            symbolsMap.clear();
            rowNumber = 0;
            ++imageId;
            continue;
        }

        for (int i = 0; i < sz(line); ++i) {
            char ch = line[i];
            if (ch != '.') symbolsMap[ch] = {rowNumber, i};
        }
        image.pb(line);
        ++rowNumber;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}
