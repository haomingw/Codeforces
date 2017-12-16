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

string s[4];

bool in(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bool win(int a, int b) {
    s[a][b] = 'x';
    int l = 0;
    REP(i, 4) REP(j, 4) {
        l = 0;
        while (in(i, j + l) && s[i][j + l] == 'x') l++;
        if (l >= 3) return true;
        l = 0;
        while (in(i + l, j) && s[i + l][j] == 'x') l++;
        if (l >= 3) return true;
        l = 0;
        while (in(i + l, j + l) && s[i + l][j + l] == 'x') l++;
        if (l >= 3) return true;
        l = 0;
        while (in(i + l, j - l) && s[i + l][j - l] == 'x') l++;
        if (l >= 3) return true;
    }
    s[a][b] = '.';
    return false;
}

int main() {
    REP(i, 4) cin >> s[i];
    REP(i, 4) REP(j, 4) {
        if (s[i][j] == '.' && win(i, j))
            return !printf("YES\n");
    }
    cout << "NO" << endl;
    return 0;
}
