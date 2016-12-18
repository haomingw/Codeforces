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
    int n, k, a, b;
    scanf("%d%d%d%d", &n, &k, &a, &b);
    string ans = "";
    char t1 = 'G', t2 = 'B';
    if (a < b) {
        swap(a, b); swap(t1, t2);
    }
    int cnt = 0;
    REP(i, n) {
        if (a >= b) {
            if (cnt == k) {
                if (b == 0) return !printf("NO\n");
                cnt = 0; b--;
                ans += t2;
            } else {
                cnt++; a--;
                ans += t1;
            }
        } else {
            cnt = 0; b--;
            ans += t2;
        }
    }
    cout << ans << endl;
    return 0;
}
