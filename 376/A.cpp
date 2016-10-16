#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, diff;
    char prev = 'a';
    for (int i = 0; i < s.size(); i++) {
        diff = abs(s[i] - prev);
        ans += min(diff, abs(diff - 26));
        prev = s[i];
    }
    cout << ans << endl;
    return 0;
}
