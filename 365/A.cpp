#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int m, c;
    int mc = 0, cc = 0;

    for (int i = 0; i < n; i++) {
        cin >> m >> c;
        if (m > c) {
            mc++;
        } else if (m < c) {
            cc++;
        }
    }

    if (mc > cc) {
	    cout << "Mishka" << endl;
    } else if (mc < cc) {
	    cout << "Chris" << endl;
    } else {
	    cout << "Friendship is magic!^^" << endl;
    }

    return 0;
}
