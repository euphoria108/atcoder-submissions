#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = "0" + s.substr(0, 3);
    cout << s << endl;
    return 0;
}
