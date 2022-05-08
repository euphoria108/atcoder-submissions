#include <iostream>

using namespace std;

int main () {
    int H, W, R, C;
    cin >> H >> W;
    cin >> R >> C;

    int bound_count = 0;
    if (R==1) {
        bound_count++;
    }
    if (R==H) {
        bound_count++;
    }
    if (C==1) {
        bound_count++;
    }
    if (C==W) {
        bound_count++;
    }

    cout << 4 - bound_count << endl;
    return 0;
}