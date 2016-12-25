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
    int n; cin >> n;
    string s; cin >> s;
    int a = n / 4, g = n / 4, c = n / 4, t = n / 4;
    vector<int> pos;
    if (n % 4 != 0) return !printf("===\n");
    REP(i, n) {
        if (s[i] == 'A') a--;
        else if (s[i] == 'G') g--;
        else if (s[i] == 'C') c--;
        else if (s[i] == 'T') t--;
        else pos.push_back(i);
    }
    if (min(min(a, g), min(c, t)) < 0) return !printf("===\n");
    for (int x : pos) {
        if (a > 0) s[x] = 'A', a--;
        else if (g > 0) s[x] = 'G', g--;
        else if (c > 0) s[x] = 'C', c--;
        else if (t > 0) s[x] = 'T', t--;
    }
    cout << s << endl;
    return 0;
}
