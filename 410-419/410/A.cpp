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
    string s;
    cin >> s;
    int n = s.size(), cnt = 0;
    REP(i, n / 2) {
        if (s[i] != s[n - i - 1]) cnt++;
    }
    if (cnt == 1 || (n & 1 && cnt == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
