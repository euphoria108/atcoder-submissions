// Couldn't solve by myself

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int searchLoop(
    int number,
    const vector< pair<int, int> > &pairVec, 
    unordered_set<int> &searched
) {
    // cout << "----- loop search begin -----" << endl;
    int loop_count = 0;
    int cursor = number;
    while (searched.count(cursor) == 0)
    {
        searched.insert(cursor);
        cursor = pairVec.at(cursor-1).second;
        // cout << "next cursor: " << cursor << endl;
        loop_count++;
    }
    // cout << "----- loop search end -----" << endl;
    return loop_count;
}

int main() {
    int N;
    cin >> N;

    vector<int> P;
    vector<int> Q;
    int buf;
    for (int i=0; i<N; i++) {
        cin >> buf;
        P.push_back(buf);
    }
    for (int i=0; i<N; i++) {
        cin >> buf;
        Q.push_back(buf);
    }

    vector< pair<int, int> > pairVec;
    for (int i=0; i<N; i++) {
        pairVec.push_back(make_pair(P.at(i), Q.at(i)));
    }
    sort(pairVec.begin(), pairVec.end());

    const int mod = 998244353; 
    
    // calc basic sequences
    vector<long long> f;
    f.push_back(0);  // i=0
    f.push_back(2);  // i=1
    f.push_back(3);  // i=2
    for (int i=3; i<=N; i++) {
        f.push_back((f.at(i - 1) + f.at(i - 2)) % mod);
    }
    vector<long long> g;
    g.push_back(0);  // i=0
    g.push_back(1);  // i=1
    g.push_back(3);  // i=2
    g.push_back(4);  // i=3
    for (int i=4; i<=N; i++) {
        g.push_back((f.at(i - 1) + f.at(i - 3)) % mod);
    }

    long long ans = 1;
    unordered_set<int> searched;
    for (int i=1; i<=N; i++) {
        // cout << "i: " << i << endl;
        if (searched.count(i) > 0){
            continue;
        }
        int loop_count = searchLoop(i, pairVec, searched);
        // cout << "loop count: " << loop_count << endl;
        ans *= g.at(loop_count);
        ans = ans % mod;
    }

    cout << ans << endl;
    return 0;
}