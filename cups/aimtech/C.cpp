#include <iostream>
#include <cstdio>
#include <cmath>
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
    string s;
    cin >> s;
    int n = SIZE(s);
    bool begin = false;
    REP(i, n) {
        if (!begin) {
            if (s[i] == 'a') continue;
            else {
                begin = true;
                s[i] -= 1;
            }
        } else {
            if (s[i] != 'a') s[i] -= 1;
            else break;
        }
    }
    if (!begin) s[n - 1] = 'z';
    cout << s << endl;
    return 0;
}
