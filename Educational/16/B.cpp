#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[300010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int index = (n - 1) / 2;
    cout << a[index] << endl;
    return 0;
}
