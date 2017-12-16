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

int main() {
    int a, b;
    cin >> a >> b;
    int n = 1e6, na = 1, nb = 2;
    REP(i, n) {
        a -= na, b -= nb;
        if (a < 0 || b < 0) break;
        na += 2, nb += 2;
    }
    if (a < 0) cout << "Vladik" << endl;
    else cout << "Valera" << endl;
    return 0;
}
