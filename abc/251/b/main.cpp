#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main () {
    int N, W;
    cin >> N >> W;
    vector<int> A;
    int buf;
    for (int i=0; i<N; i++) {
        cin >> buf;
        A.push_back(buf);
    }

    sort(A.begin(), A.end());

    set<int> appeared;
    for (int i=0; i<N; i++) {
        const int &a = A.at(i);
        if (a > W) {break;}
        if (appeared.count(a) == 0) {
            appeared.insert(a);
        }
    }

    if (N >= 2) {
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                const int &a = A.at(i);
                const int &b = A.at(j);
                int x = a + b;
                if (x > W) {break;}
                if (appeared.count(x) == 0) {
                    appeared.insert(x);
                }
            }
        }
    }

    if (N >= 3) {
        for (int i=0; i<N-2; i++) {
            for (int j=i+1; j<N-1; j++) {
                for (int k=j+1; k<N; k++) {
                    const int &a = A.at(i);
                    const int &b = A.at(j);
                    const int &c = A.at(k);
                    int x = a + b + c;
                    if (x > W) {break;}
                    if (appeared.count(x) == 0) {
                        appeared.insert(x);
                    }
                }
            }
        }
    }

    cout << appeared.size() << endl;
    return 0;

}