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
    int n;
    scanf("%d", &n);
    int a, b, pa, pb;
    bool sure = false;
    REP(i, n) {
        scanf("%d%d", &a, &b);
        if (a != b) return !printf("rated\n");
        if (i > 0 && pa < a && pb < b) sure = true;
        pa = a, pb = b;
    }
    if (sure) cout << "unrated" << endl;
    else cout << "maybe" << endl;
    return 0;
}
