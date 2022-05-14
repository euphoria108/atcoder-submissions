// couldn't solve

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

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

    vector <long long> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = A[1];
    for (int i=2; i<=N-1; i++) {
        if (dp[i-1] == dp[i-2]) {
            dp[i] = dp[i-2] + A[i];
        } else {
            dp[i] = min(dp[i-1], dp[i-2] + A[i]);
        }
    }

    vector <long long> dp2(N+1, 0);
    dp2[0] = 0;
    dp2[1] = 0;
    for (int i=2; i<=N; i++) {
        if (dp2[i-1] == dp2[i-2]) {
            dp2[i] = dp2[i-2] + A[i];
        } else {
            dp2[i] = min(dp2[i-1], dp2[i-2] + A[i]);
        }
    }

    cout << min(dp[N-1], dp2[N]) << endl;

    return 0;
}