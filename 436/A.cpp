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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 105;
int a[maxn];

int main() {
    int n, x;
    scanf("%d", &n);
    set<int> s;
    REP(i, n) {
        scanf("%d", &x);
        a[x] += 1;
        s.insert(x);
    }
    int first = *s.begin();
    if (s.size() == 2 && a[first] == n / 2) {
        cout << "YES" << endl;
        cout << first << " " << *(++s.begin()) << endl;
    } else
        cout << "NO" << endl;
    return 0;
}
