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

bool isPalindrome(int x) {
    string s = to_string(x);
    int n = s.size();
    REP(i, n / 2) if (s[i] != s[n - 1 - i]) return false;
    return true;
}

int main() {
    int x;
    cin >> x;
    while (x % 10 == 0) x /= 10;
    cout << (isPalindrome(x) ? "YES" : "NO") << endl;
    return 0;
}
