#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<string> s;
    vector<string> t;

    cin >> N;
    string s_buf;
    string t_buf;
    for (int i=0; i<N; i++) {
        cin >> s_buf >> t_buf;
        s.push_back(s_buf);
        t.push_back(t_buf);
    }

    // concat
    vector<string> all_names;
    all_names.insert(all_names.end(), s.begin(), s.end());
    all_names.insert(all_names.end(), t.begin(), t.end());

    bool flag = true;
    for (int i=0; i<N; i++) {
        if (
            s.at(i) != t.at(i) &&
            count(all_names.begin(), all_names.end(), s.at(i)) >= 2 &&
            count(all_names.begin(), all_names.end(), t.at(i)) >= 2
        ) {
            flag = false;
            break;
        } else if (
            s.at(i) == t.at(i) &&
            count(all_names.begin(), all_names.end(), s.at(i)) >= 3 &&
            count(all_names.begin(), all_names.end(), t.at(i)) >= 3
        ) {
            flag = false;
            break;
        }
    }

    if (flag == true) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}