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

const int maxn = 2e5 + 5;
int a[maxn], used[maxn], used2[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &a[i]);
        used[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) q.push(i);
    }
    int ans = q.size();
    REP(i, n) {
        if (used[a[i]] > 1 && a[i] > q.front()) {
            used[a[i]]--;
            a[i] = q.front();
            q.pop();
            continue;
        }
        used2[a[i]]++;
        if (used2[a[i]] > 1) {
            used[a[i]]--, used2[a[i]]--;
            a[i] = q.front();
            q.pop();
        }
    }
    printf("%d\n", ans);
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
