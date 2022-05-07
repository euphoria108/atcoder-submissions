#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <utility>

using namespace std;


// https://stackoverflow.com/a/28698654
vector< vector<int> > comb(int N, int K)
{
    vector< vector<int> > res;
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
 
    // print integers and permute bitmask
    do {
        vector<int> res_inner;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) res_inner.push_back(i);
        }
        res.push_back(res_inner);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    return res;
}

int count(const vector<string>& S, int K){
    map<char, int> counter;
    for (const auto& s: S) {
        for (const auto& chr: s) {
            if (counter.count(chr) == 0) {
                counter.insert(make_pair(chr, 1));
            } else {
                counter.at(chr)++;
            }
        }
    }
    
    int res_count = 0;
    for (const auto& it: counter) {
        auto& [chr, count] = it;
        if (count == K) {
            res_count++;
        }
    }
    return res_count;
}

int main () {
    int N, K;
    cin >> N >> K;
    // cout << "N: " << N << " K: " << K << endl;
    vector<string> S;
    string buf;
    for (int i=0;i<N;i++) {
        cin >> buf;
        S.push_back(buf);
    }

    int ans = 0;
    for (int i=1;i<=N;i++) {
        // cout << "i: " << i << endl;
        auto cmb_vec = comb(N, i);
        for (auto& cmb: cmb_vec) {
            vector<string> substr;
            for (auto& j: cmb) {
                substr.push_back(S.at(j));
            }
            ans = max(count(substr, K), ans);
            // cout << "ans: " << ans << endl;
        }
    }

    cout << ans << endl;
}
