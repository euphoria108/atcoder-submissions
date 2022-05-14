#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <any>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; i++) {
        cin >> a.at(i);
    }
    vector<int> b(N);
    for (int i=0; i<N; i++) {
        cin >> b.at(i);
    }
    int Q;
    cin >> Q;
    vector<int> x, y;
    int xbuf, ybuf;
    for (int i=0; i<Q; i++) {
        cin >> xbuf >> ybuf;
        x.push_back(xbuf);
        y.push_back(ybuf);
    }

    for (int i=0; i<Q; i++) {
        int x_ = x.at(i);
        int y_ = y.at(i);
        set<int> seta(a.begin(), a.begin() + x_);
        set<int> setb(b.begin(), b.begin() + y_);
        if (seta == setb) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
