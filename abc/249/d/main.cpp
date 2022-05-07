#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

// brute-force: O(n^3)


int main () {
    int N;
    cin >> N;
    vector<int> A;
    int buf;
    for (int i=0; i<N; i++) {
        cin >> buf;
        A.push_back(buf);
    }

    map<int, int> counter;
    for (const auto& a: A) {
        if (counter.count(a) == 0) {
            counter.insert(make_pair(a, 1));
        } else {
            counter.at(a)++;
        }
    }

    long long ans = 0;
    size_t n_distinct = counter.size();
    vector<int> c_keys;
    auto c_it = counter.begin();
    for (int i=0; i<n_distinct; i++){
        const auto& [key, val] = *c_it;
        c_keys.push_back(key);
        // cout << "key: " << key << " count: " << counter.at(key) << endl;
        c_it++;
    }
    long long c_max = *max_element(c_keys.begin(), c_keys.end());
    for (int i=0; i<n_distinct; i++){
        for (int j=i; j<n_distinct; j++) {
            long long l = c_keys.at(i);
            long long m = c_keys.at(j);
            long long n = l * m;
            if (n > c_max) {
                break;
            }
            if (counter.count(n) > 0) {
                if (l == m && m == n) {
                    ans += pow(counter.at(l), 3);
                }
                else if (l != m && m != n) {
                    ans += 2 * counter.at(l) * counter.at(m) * counter.at(n);
                } else if (l != m && m == n) {
                    ans += 2 * counter.at(l) * pow(counter.at(m), 2);
                } else {
                    ans += counter.at(l) * counter.at(m) * counter.at(n);
                }
            }
        }
    }

    cout << ans << endl;

}
