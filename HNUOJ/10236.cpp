#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    while (cin >> n) {
        if (n % 2 == 0 || n == 1) {
            cout << "2^? mod 2 = 1\n";
            continue;
        }

        for (int i = 1; i < 1000; i++) {
            int num = 1 << i;

            if (num % n == 1) {
                cout << "2^" << i << " mod " << n << " = 1" << '\n';
                break;
            }
        }
    }

    return 0;
}
