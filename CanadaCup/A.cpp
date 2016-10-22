#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') a++;
        else break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '>') b++;
        else break;
    }
    cout << a + b << endl;
    return 0;
}
