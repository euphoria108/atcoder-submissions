#include <iostream>

using namespace std;

int main () {
    int N, A, B;
    cin >> N >> A >> B;

    for (int i=0; i<N; i++){
        for (int a=0; a<A; a++) {
            for (int j=0; j<N; j++){
                for (int b=0; b<B; b++) {
                    if ((i + j) % 2 == 0) {
                        cout << ".";
                    } else {
                        cout << "#";
                    }
                }
            }
            cout << endl;
        }
    }    
}