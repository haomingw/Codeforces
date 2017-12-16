#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
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

const int maxn = 2e5 + 5;
int f[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q, r;
    cin >> n >> m >> q;
    unordered_map<string, int> hmap;
    string s, t;
    REP(i, n) {
        cin >> s; hmap[s] = i;
        f[i] = i, f[i + n] = i + n;
    }
    int a, b;
    REP(i, m) {
        cin >> r >> s >> t;
        a = hmap[s], b = hmap[t];
        if (r == 1) {
            if (find(a) == find(b + n)) cout << "NO" << endl;
            else {
                f[find(a)] = find(b);
                f[find(a + n)] = find(b + n);
                cout << "YES" << endl;
            }
        } else {
            if (find(a) == find(b)) cout << "NO" << endl;
            else {
                f[find(a)] = f[find(b + n)];
                f[find(a + n)] = f[find(b)];
                cout << "YES" << endl;
            }
        }
    }
    REP(i, q) {
        cin >> s >> t;
        a = hmap[s], b = hmap[t];
        if (find(a) == find(b)) r = 1;
        else if (find(a) == find(b + n)) r = 2;
        else r = 3;
        cout << r << endl;
    }
    return 0;
}
