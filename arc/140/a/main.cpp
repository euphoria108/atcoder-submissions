#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// https://algo-logic.info/divisor/
vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // sort in ascending order
    return ret;
}

// https://www.geeksforgeeks.org/frequent-element-array/
int mostFrequent(const vector<char> &arr, int n)
{
    // Insert all elements in hash.
    map<char, int> hash;
    for (int i = 0; i < n; i++) {
        hash[arr.at(i)]++;
        // cout << "char: " << arr.at(i) << endl;
        // cout << "count: " << hash.at(arr.at(i)) << endl;
    }

    // find the max frequency
    int max_count = 0, res = -1;
    for (auto i : hash) {
        // cout << "i.first: " << i.first << " i.second: " << i.second << endl;
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return max_count;
}

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    auto divs = divisor(S.size());

    for (const auto& d: divs) {
        if (d == N) {break;}
        // cout << "d: " << d << endl;
        int need_cng = 0;
        for (int i=0; i<d; i++) {
            vector<char> subarr;
            for (int j=i; j<N; j+=d) {
                subarr.push_back(S.at(j));
            }
            // cout << "subarr size: " << subarr.size() << endl;
            auto max_cnt = mostFrequent(subarr, subarr.size());
            // cout << "max_cnt: " << max_cnt << endl;
            need_cng += (N / d) - max_cnt;
        }
        // cout << "need_cng: " << need_cng << endl;
        if (need_cng <= K) {
            cout << d << endl;
            return 0;
        }
    }

    cout << N << endl;
    return 0;
}
 