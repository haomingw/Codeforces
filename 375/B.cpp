#include <iostream>
#include <cstdio>
using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    int n;
    cin >> n;
    char c[300];
    scanf("%s", c);

    int ain = 0, aout = 0, lout = 0;
    bool fp = false, fw = false;
    for (int i = 0; i < n; i++) {
        if (c[i] == '(') {fp = true; fw = false; aout = max(aout, lout); lout = 0; continue;}
        if (c[i] == ')') {fp = false; continue;}
        if (isLetter(c[i])) {
            if (fp) {
                if (!fw) {ain++; fw = true;}
            }
            else lout++;
            if (i == n - 1) aout = max(aout, lout);
        } else {
            if (fp) fw = false; else aout = max(aout, lout);
            lout = 0;
        }
    }
    cout << aout << " " << ain << endl;
    return 0;
}
