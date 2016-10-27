#include <iostream>
using namespace std;

char c;
int r;

int main() {
    cin >> c >> r;
    bool h = (r == 1 || r == 8), v = (c == 'a' || c == 'h');
    int ans;
    if (h && v) ans = 3;
    else if (h || v) ans = 5;
    else ans = 8;
    cout << ans << endl;
    return 0;
}
