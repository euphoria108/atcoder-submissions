#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

int main () {
    int Q;
    cin >> Q;

    deque<tuple<long long, long long> > cylinder;

    bool printed = false;
    for (int i=0; i<Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            // insert query
            long long x, c;
            cin >> x >> c;

            cylinder.push_back(make_tuple(x, c));

        } else if (q == 2) {
            // pop query
            int c;
            cin >> c;

            long long sum_value = 0;
            long long took_count = 0;
            while (took_count < c)
            {
                auto [val, num] = cylinder.front();
                cylinder.pop_front();
                // review: here become more simple with min operation
                if (num > c - took_count)
                {
                    long long take_count = c - took_count;
                    sum_value += val * take_count;
                    took_count += take_count;
                    cylinder.push_front(make_tuple(val, num - take_count));
                } else {
                    sum_value += val * num;
                    took_count += num;
                }
            }
            
            cout << sum_value << endl;
            printed = true;
        } else {
            throw;
        }
    }

    if (!printed) {
        cout << endl;
    }

    return 0;
}