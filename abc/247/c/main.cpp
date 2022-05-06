#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string res = "1";
    for (auto i=2; i<=N; i++) {
        res = res + " " + to_string(i) + " " + res;
    }

    cout << res << endl;
}

/* review: I can do better with
 * - recursive call
 * - DP + memorized recursion
 */
