#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<string> S;
    vector<long long> T;
    string s_buf;
    long long t_buf;
    for (int i=0; i<N; i++) {
        cin >> s_buf >> t_buf;
        S.push_back(s_buf);
        T.push_back(t_buf);
    }

    set<string> seen;
    int order;
    long long point = 0;
    for (int i=0; i<N; i++) {
        const string &s = S.at(i);
        const long long &t = T.at(i);
        if (seen.count(s) > 0) {continue;}
        if (t > point) {
            order = i + 1;
            point = t;
        }
        seen.insert(s);
    }

    cout << order << endl;

    return 0;
}
 