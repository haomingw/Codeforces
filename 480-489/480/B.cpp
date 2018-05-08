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

const int maxn = 105;
vector<string> city;

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, 4) city.push_back(string(n, '.'));
    if (k & 1) {
        int mid = n / 2;
        if (k <= n - 2) REPP(i, mid - k / 2, mid + k / 2 + 1) city[1][i] = '#';
        else {
            REPP(i, 1, n - 1) city[1][i] = '#';
            k -= n - 2;
            REP(i, k / 2) city[2][1 + i] = city[2][n - 2 - i] = '#';
        }
    } else {
        REP(i, k / 2) {
            city[1][i + 1] = city[2][i + 1] = '#';
        }
    }
    cout << "YES" << endl;
    REP(i, 4) cout << city[i] << endl;
    return 0;
}
