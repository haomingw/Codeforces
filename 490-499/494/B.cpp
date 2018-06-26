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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    int n = (x + 1) / 2;
    string s = "";
    REP(i, n) s += "01", a--, b--;
    if (x & 1) {
        REP(i, a) s = "0" + s;
        REP(i, b) s = s + "1";
    } else {
        if (a > b) {
            REP(i, a - 1) s = "0" + s;
            REP(i, b) s = s + "1";
            s += "0";
        } else {
            REP(i, a) s = "0" + s;
            REP(i, b - 1) s = s + "1";
            s = "1" + s;
        }
    }
    cout << s << endl;
    return 0;
}
