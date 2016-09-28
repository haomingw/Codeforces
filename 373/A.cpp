#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        if (a[0] == 15) {
            return !printf("DOWN\n");
        } else if (a[0] == 0) {
            return !printf("UP\n");
        } else {
            return !printf("-1\n");
        }
    }
    int diff = a[n - 1] - a[n - 2];
    if (diff > 0) {
        if (a[n - 1] == 15) return !printf("DOWN\n");
        else return !printf("UP\n");
    } else {
        if (a[n - 1] == 0) return !printf("UP\n");
        else return !printf("DOWN\n");
    }
    return 0;
}
