#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int query(int a , int b) {
    int res;
    cout << "?" << " " << a + 1 << " " << b + 1 << endl;
    fflush(stdout);
    cin >> res;
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int x = query(0, 1);
    int y = query(0, 2);
    int z = query(1, 2);
    a[0] = (x + y - z) / 2;
    a[1] = x - a[0];
    a[2] = y - a[0];

    for (int i = 3; i < n; i++) {
        a[i] = query(0, i) - a[0];
    }
    cout << "!";
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout << endl;
    fflush(stdout);
    return 0;
}
