#include <iostream>

using namespace std;


int main () {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int taka_loop = A + C;
    int aoki_loop = D + F;
    int q_taka = X / taka_loop;
    int r_taka = X % taka_loop;
    int q_aoki = X / aoki_loop;
    int r_aoki = X % aoki_loop;
    int taka_pos = q_taka * A * B + B * min(r_taka, A);
    int aoki_pos = q_aoki * D * E + E * min(r_aoki, D);

    if (taka_pos > aoki_pos) {
        cout << "Takahashi" << endl;
    } else if (aoki_pos > taka_pos) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}
