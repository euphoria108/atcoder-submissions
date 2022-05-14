#include <iostream>
#include <string>

using namespace std;


int main () {
    string s;
    cin >> s;
    int rep = 6 / s.size();
    for (int i=0; i<rep; i++) {
        cout << s;
    }
    cout << endl;
    return 0;
}