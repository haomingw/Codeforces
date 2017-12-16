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

int a, b;
string s;

void parse() {
    a = (s[0] - '0') * 10 + s[1] - '0';
    b = (s[3] - '0') * 10 + s[4] - '0';
}

void add() {
    b++;
    if (b >= 60) b -= 60, a++;
    if (a == 24) a = 0;
}

bool isPalindrome() {
    return a / 10 == b % 10 && a % 10 == b / 10;
}

int main() {
    cin >> s;
    parse();
    REP(i, 3600) {
        if (isPalindrome())
            return !printf("%d\n", i);
        add();
    }
    return 0;
}
