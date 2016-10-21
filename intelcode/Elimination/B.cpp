#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
typedef long long ll;

char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool isVowel(char a) {
    REP(i,6) {
        if (a == vowels[i]) return true;
    }
    return false;
}

int count(string s) {
    int cnt = 0, n = SIZE(s);
    REP(i, n) cnt += isVowel(s[i]);
    return cnt;
}

int p[110];

int main() {
    int n;
    cin >> n;
    REP(i, n) cin >> p[i];

    string s;
    getline(cin, s);
    REP(i, n) {
        getline(cin, s);
        // clog << count(s) << endl;
        if (count(s) != p[i]) return !printf("NO\n");
    }
    cout << "YES" << endl;
    return 0;
}
