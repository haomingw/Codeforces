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

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    string s, t;
    cin >> s >> t;
    int a[26];
    REP(i, 26) a[s[i] - 'a'] = t[i] - 'a';
    cin >> s;
    REP(i, SZ(s)) {
        if (isUpper(s[i])) cout << char(a[s[i] - 'A'] + 'A');
        else if (isLower(s[i])) cout << char(a[s[i] - 'a'] + 'a');
        else cout << s[i];
    }
    cout << endl;
    return 0;
}
