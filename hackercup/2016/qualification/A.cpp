#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int dist(pii& p, pii& q) {
    int a = p.first - q.first, b = p.second - q.second;
    return a * a + b * b;
}

int solve(vector<pii>& a) {
    int n = SIZE(a), cnt = 0;
    REP(i, n) {
        vector<int> d;
        unordered_map<int, int> hmap;
        REP(j, n) {
            if (j == i) continue;
            vector<int> ds;
            int d = dist(a[i], a[j]);
            hmap[d] += 1;
        }
        for (auto it = hmap.begin(); it != hmap.end(); it++) {
            int x = it->second;
            cnt += x * (x - 1) / 2;
        }
    }
    return cnt;
}

int main() {
    int T, n;
    cin >> T;
    REP(t, T) {
        vector<pii> stars;
        cin >> n;
        int x, y;
        REP(i, n) {
            cin >> x >> y;
            stars.push_back(MP(x, y));
        }
        cout << "Case #" << t + 1 << ": " << solve(stars) << endl;
    }
    return 0;
}
