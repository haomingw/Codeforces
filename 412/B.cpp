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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

bool selected(int x, int target) {
    int a = x / 50 % 475;
    REP(i, 25) {
        a = (a * 96 + 42) % 475;
        if (a + 26 == target) return true;
    }
    return false;
}

int main() {
    int p, x, y;
    cin >> p >> x >> y;
    int a = inf, b = inf, c = x;
    REP(i, x) {
        if (selected(c, p)) return !printf("0\n");
        c -= 50;
        if (c < y) break;
    }
    REPP(i, 1, 20000) {
        c = x + 100 * i;
        if (selected(c, p) || selected(c - 50, p)) {
            b = i; break;
        }
    }
    cout << min(a, b) << endl;
    return 0;
}
