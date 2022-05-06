// Couldn't solve by myself

// sliding window solution
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countSubarr(const vector<int> &vec, int X, int Y) {
    int i = 0;
    int j = 0;
    long long count = 0;
    int countX = 0;
    int countY = 0;
    while (i < vec.size())
    {
        while(j < vec.size() && (countX == 0 || countY == 0)) {
            if (vec.at(j) == X) {
                countX++;
            }
            if (vec.at(j) == Y) {
                countY++;
            }
            j++;
        }
        if (countX > 0 && countY > 0) {
            count += vec.size() - j + 1;
        }
        if (vec.at(i) == X) {
            countX--;
        }
        if (vec.at(i) == Y) {
            countY--;
        }
        i++;
    }
    return count;
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A;
    int a_buf;
    for (int i=0; i<N; i++) {
        cin >> a_buf;
        A.push_back(a_buf);
    }

    vector<int> subarr;
    long long count = 0;
    for (const auto val: A) {
        if (val > X || val < Y) {
            if (subarr.size() >= 1) {
                count += countSubarr(subarr, X, Y);
            }
            subarr.clear();
        } else {
            subarr.push_back(val);
        }
    }
    if (subarr.size() >= 1) {
        count += countSubarr(subarr, X, Y);
    }
    
    cout << count << endl;
    return 0;
}