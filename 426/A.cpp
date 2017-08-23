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

int main() {
    char a, b;
    scanf("%c %c", &a, &b);
    map<char, int> mp;
    mp['v'] = 0; mp['<'] = 1;
    mp['^'] = 2; mp['>'] = 3;
    int n;
    scanf("%d", &n);
    n %= 4;
    int rotate = (mp[b] - mp[a] + 4) % 4;
    if (rotate & 1) {
        if (rotate == n) cout << "cw" << endl;
        else cout << "ccw" << endl;
    } else
        cout << "undefined" << endl;
    return 0;
}


