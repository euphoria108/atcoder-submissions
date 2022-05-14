// couldn't solve by myself

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <any>

using namespace std;

constexpr int MAXP = 1000005;

vector<long long> generate_plist() {
    vector<long long> prime_list;
    vector<bool> el_list(MAXP, false);
    for (long long i=2; i<MAXP; i++) {
        if (el_list.at(i)) {continue;}
        prime_list.push_back(i);
        for (long long j=i; j<MAXP; j+=i) {
            el_list.at(j) = true;
        }
    }
    return prime_list;
}

long long f(long long p, long long q) {
    double est = 1;
    est *= q;
    est *= q;
    est *= q;
    est *= p;
    if (est > 4e18) {
        return 4e18;
    }
    return p * q * q * q;
}


int main() {
    long long N;
    cin >> N;

    auto p_list = generate_plist();

    long long res = 0;
    int j = p_list.size() - 1;
    for (long long i=0; i<p_list.size(); i++) {
        while (i < j && f(p_list.at(i), p_list.at(j)) > N) {
            j--;
        }
        if (i >= j) {
            break;
        }
        res += j - i;
    }

    cout << res << endl;
    return 0;
}