#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
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

int solve(int n) {
    int a[n], ans = 0;
    REP(i, n) cin >> a[i];
    int diff, ind = -1, add = 0;
    REP(i, n) {
        ind = (ind + 1) % 4;
        if (ind == 3) {
            ind = -1;
            continue;
        }
        diff = a[i + 1] - a[i];
        if (diff <= 0) {
            add += 3 - ind;
            ind = -1;
        } else if (diff > 10) {
            int nb = (diff - 1) / 10, np = 2 - ind; // nombre de places
            if (np < nb) { // cannot fill between the 2 elements
                add += 3 - ind;
                ind = -1;
            } else {
                add += nb;
                ind += nb;
            }
        }
    }
    return add;
}

int main() {
    int T, N;
    cin >> T;
    REP(t, T) {
        cin >> N;
        cout << "Case #" << t + 1 << ": " << solve(N) << endl;
    }
    return 0;
}
