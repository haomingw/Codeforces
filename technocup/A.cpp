#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

bool isMulti(int a) {
    return a % 2 == 0;
}

bool isPending(int a) {
    return a % 10 == 1;
}

int revMulti(int a) {
    return a / 2;
}

int revPending(int a) {
    return (a - 1) / 10;
}

int main() {
    int a, b;
    cin >> a >> b;
    int tmp = b;
    vector<int> x;
    x.push_back(tmp);

    while (tmp) {
        if (isMulti(tmp)) {
            tmp = revMulti(tmp);
            x.push_back(tmp);
            if (tmp == a) break;
        } else if (isPending(tmp)) {
            tmp = revPending(tmp);
            x.push_back(tmp);
            if (tmp == a) break;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (tmp != a) return !printf("NO\n");
    cout << "YES" << endl;
    cout << x.size() << endl;
    for (int i = x.size() - 1; i > 0; i--)
        cout << x.at(i) << " ";
    cout << x.at(0) << endl;
    return 0;
}
