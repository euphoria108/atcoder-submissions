#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


void pr(int mi, int ma, int st) {
    // cout << "mi: " << mi << " ma: " << ma << " st: " << st << endl;
    int p = st;
    int q = st;
        cout << st;
    if (st - mi <= (ma - mi)/2) {
        while (p > mi || q < ma) {
            if (q < ma) {
                cout << " ";
                q++;
                cout << q;
            }
            if (p > mi) {
                cout << " ";
                p--;
                cout << p;
            }
        }
    } else {
        while (p > mi || q < ma) {
            if (p > mi) {
                cout << " ";
                p--;
                cout << p;
            }
            if (q < ma) {
                cout << " ";
                q++;
                cout << q;
            }
        }
    }
}

int main () {
    int N, X;
    cin >> N >> X;

    if (min(X, N-X) < N/3 && X < N/2) {
        cout << X << " ";
        pr(X+1, N, X + (N-X-1)/2);
        int p = X-1;
        while (p >= 1) {
            cout << " ";
            cout << p;
            p--;
        }
    } else if (min(X, N-X) < N/3 && X > N/2) {
        cout << X << " ";
        pr(1, X-1, X/2);
        int q = X+1;
        while (q <= N) {
            cout << " ";
            cout << q;
            q++;
        }
    } else {
        pr(1, N, X);
    }

    cout << endl;
    return 0;
}
