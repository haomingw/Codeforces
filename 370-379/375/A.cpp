#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans;
    ans = max(max(abs(a - b), abs(b - c)), abs(a - c));
    cout << ans << endl;
    return 0;
}
