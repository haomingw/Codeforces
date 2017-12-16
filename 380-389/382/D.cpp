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

bool isPrime(int n) {
    int i = 3;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i += 2;
    }
    return true;
}

int main() {
    int n, ans;
    cin >> n;
    if (n == 2) ans = 1;
    else if (n % 2 == 0) ans = 2;
    else {
        if (isPrime(n)) ans = 1;
        else {
            if (isPrime(n - 2)) ans = 2;
            else ans = 3;
        }
    }
    cout << ans << endl;
    return 0;
}
