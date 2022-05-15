#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void countReplaceR(string str, int &count);
void countReplaceAC(string str, int &count);

void countReplaceR(string str, int &count) {
    auto foundARC = str.find("ARC");
    auto foundAARCC = str.find("AARCC");
    if (foundAARCC != string::npos) {
        count++;
        str.replace(str.begin()+foundAARCC+1, str.begin()+foundAARCC+4, "R");
        countReplaceAC(str, count);
    } else if (foundARC != string::npos) {
        count++;
        str.replace(str.begin()+foundARC, str.begin()+foundARC+3, "R");
        countReplaceAC(str, count);
    }
}

void countReplaceAC(string str, int &count) {
    auto foundARC = str.find("ARC");
    auto foundAARCC = str.find("AARCC");
    if (foundARC != string::npos) {
        count++;
        str.replace(str.begin()+foundARC, str.begin()+foundARC+3, "AC");
        countReplaceR(str, count);
    } else if (foundAARCC != string::npos) {
        count++;
        str.replace(str.begin()+foundAARCC+1, str.begin()+foundAARCC+4, "AC");
        countReplaceR(str, count);
    }
}


int main () {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count = 0;
    countReplaceR(S, count);

    // cout << "countR: " << countR << endl;
    // cout << "countAC: " << countAC << endl;
    cout << count << endl;

    return 0;
}