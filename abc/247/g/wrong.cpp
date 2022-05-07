// wrong

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> A, B, C;
    int a_buf, b_buf, c_buf;
    for (int i=0; i<N; i++) {
        cin >> a_buf >> b_buf >> c_buf;
        A.push_back(a_buf);
        B.push_back(b_buf);
        C.push_back(c_buf);
    }

    // find max power per distinct (A, B)
    map< pair<int, int>, int> edge_len;
    for (int i=0; i<N; i++) {
        pair<int, int> key = make_pair(A.at(i), B.at(i));
        if (edge_len.count(key) > 0) {
            edge_len.at(key) = max(edge_len.at(key), C.at(i));
        } else {
            edge_len.insert(make_pair(key, C.at(i)));
        }
    }

    // auto itr = edge_len.begin();
    // for (size_t i=1; i<=edge_len.size(); i++) {
    //     const auto& [key, val] = *itr;
    //     const auto& [a_val, b_val] = key;
    //     cout << "a: " << a_val << " b: " << b_val << " c: " << val << endl;
    //     itr++;
    // }

    // cound distinct elements
    set<int> dis_a(A.begin(), A.end());
    set<int> dis_b(B.begin(), B.end());
    int max_member = min(dis_a.size(), dis_b.size());

    vector< vector<long long>> dp(edge_len.size()+1, vector<long long>(max_member+1, 0));
    vector< vector< set<int> > > a_used(edge_len.size()+1, vector< set<int> >(max_member+1, set<int>()));
    vector< vector< set<int> > > b_used(edge_len.size()+1, vector< set<int> >(max_member+1, set<int>()));
    auto itr = edge_len.begin();
    for (size_t i=1; i<=edge_len.size(); i++) {
        const auto& [key, val] = *itr;
        const auto& [a_val, b_val] = key;
        // cout << "a_val: " << a_val << " b_val: " << b_val << endl;
        for (int j=1; j<=max_member; j++) {
            if (j == 1 ||
                (j >= 2 
                && a_used[i-1][j-1].count(a_val)==0 
                && b_used[i-1][j-1].count(b_val)==0
                && dp[i-1][j-1]>0)) {
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i-1][j-1] + edge_len.at(make_pair(a_val, b_val))
                );
                // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " from max{" << dp[i-1][j] << ", " << dp[i-1][j-1] << "+" << edge_len.at(make_pair(a_val, b_val)) << "}" << endl;
                if (dp[i][j] > dp[i-1][j]){
                    a_used[i][j] = a_used[i-1][j-1];
                    a_used[i][j].insert(a_val);
                    b_used[i][j] = b_used[i-1][j-1];
                    b_used[i][j].insert(b_val);
                }
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
        itr++;
    }

    cout << max_member << endl;
    for (int i=1; i<=max_member; i++) {
        cout << dp[edge_len.size()][i] << endl;
    }

}