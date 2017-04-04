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
    int n, m, k , x;
    scanf("%d%d", &n, &m);
    map<int, int> mp;
    REP(i, m) {
        scanf("%d", &k);
        mp.clear();
        bool risk = true;
        REP(j, k) {
            scanf("%d", &x);
            if (mp.count(x)) risk = false;
            else mp[-x] = 1;
        }
        if (risk) return !printf("YES\n");
    }
    cout << "NO" << endl;
    return 0;
}
