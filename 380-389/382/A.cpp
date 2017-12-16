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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int src, tgt;
    REP(i, n) {
        if (s[i] == 'G') src = i;
        if (s[i] == 'T') tgt = i;
    }
    int diff = abs(src - tgt);
    if (diff % k != 0) return !printf("NO\n");
    int debut = src;
    if (src > tgt) {
        while (debut > tgt) {
            if (s[debut] == '#') return !printf("NO\n");
            debut -= k;
        }
    } else {
        while (debut < tgt) {
            if (s[debut] == '#') return !printf("NO\n");
            debut += k;
        }
    }
    cout << "YES" << endl;
    return 0;
}
