#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main () {
    string S;
    cin >> S;

    // cout << S << endl;
    // cout << set<char>(S.begin(), S.end()).size() << endl;
    if (
        any_of(S.begin(), S.end(), ::islower)
        && any_of(S.begin(), S.end(), ::isupper)
        && set<char>(S.begin(), S.end()).size() == S.size()
    ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}