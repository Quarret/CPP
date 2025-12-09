#include <iostream>
using namespace std;

long long a[55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 55; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << a[num] << '\n';
    }
    return 0;
}
