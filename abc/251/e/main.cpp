// couldn't solve

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long inf = 1e18;

int main () {
    int N;
    cin >> N;
    vector<long long> A;
    long long buf;
    A.push_back(0);
    for (int i=0; i<N; i++) {
        cin >> buf;
        A.push_back(buf);
    }

    long long ans = inf;

    // case1: first action is not performed
    vector< vector<long long> > dp(N+1, vector<long long>(2, 0));
    dp[1][0] = 0;
    dp[1][1] = inf;
    for (int i=2; i<=N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + A.at(i);
    }

    ans = min(ans, dp[N][1]);

    // case2: first action is performed
    dp[1][0] = inf;
    dp[1][1] = A.at(1);
    for (int i=2; i<=N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + A.at(i);
    }

    ans = min(ans, min(dp[N][1], dp[N][0]));

    cout << ans << endl;

    return 0;
}