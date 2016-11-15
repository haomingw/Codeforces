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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    REP(i, n) {
        if (s[i] == 'A') a++;
        else b++;
    }
    if (a > b) cout << "Anton" << endl;
    else if (a == b) cout << "Friendship" << endl;
    else cout << "Danik" << endl;
    return 0;
}
