#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <any>

using namespace std;

int main () {
    int N, Q;
    cin >> N >> Q;
    vector<int> X;
    int buf;
    for (int i=0; i<Q; i++) {
        cin >> buf;
        X.push_back(buf);
    }

    map<int, int> mp;
    vector<int> v;
    for (int i=0; i<N; i++) {
        mp.insert(make_pair(i+1, i));
        v.push_back(i+1);
    }

    for (auto& val: X) {
        // cout << "val: " << val << endl;
        int pos = mp.at(val);
        // cout << "pos: " << pos << endl;
        if (pos < N-1) {
            int val2 = v.at(pos+1);
            swap(v.at(pos), v.at(pos+1));
            mp.at(val2) = pos;
            mp.at(val) = pos+1;
        } else {
            int val2 = v.at(pos-1);
            swap(v.at(pos), v.at(pos-1));
            mp.at(val2) = pos;
            mp.at(val) = pos-1;
        }
    }

    for (int i=0; i<N; i++) {
        cout << v.at(i);
        if (i < N-1) cout << " ";
        else cout << endl;
    }
    return 0;
}