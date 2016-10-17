#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(x) (x).begin(), (x).end()

vector<string> w = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
    string s, t;
    cin >> s >> t;
    int a, b;
    a = find(ALL(w), s) - w.begin();
    b = find(ALL(w), t) - w.begin();
    // clog << a << " " << b << endl;
    if ((a + 28) % 7 == b || (a + 30) % 7 == b || (a + 31) % 7 == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
