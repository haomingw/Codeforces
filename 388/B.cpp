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

int main() {
    int x[3], y[3];
    REP(i, 3) cin >> x[i] >> y[i];
    cout << 3 << endl;
    REP(i, 3) {
        int ind1 = i, ind2 = (i + 1) % 3, ind3 = (i + 2) % 3;
        int xx = x[ind1] + x[ind2] - x[ind3];
        int yy = y[ind1] + y[ind2] - y[ind3];
        cout << xx << " " << yy << endl;
    }
    return 0;
}
