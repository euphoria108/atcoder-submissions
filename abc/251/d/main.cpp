// Couldn't solve

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// solve for W = 10^6
int main () {
    int W;
    cin >> W;

    cout << 99*3 + 1 << endl;

    for (int i=1; i<100; i++) {
        cout << i << " ";
    }
    for (int i=1; i<100; i++) {
        cout << 100*i << " ";
    }
    for (int i=1; i<100; i++) {
        cout << 10000*i << " ";
    }
    cout << 1 << endl;

    return 0;
}
