#include <iostream>
using namespace std;

long long f[65], g[65];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    f[1] = 1;
    g[1] = 1, g[2] = 0, g[3] = 1;
    for (int i = 4; i < 65; i++) {
        g[i] =  g[i - 1] + g[i - 3];
    }

    for (int i = 2; i < 65; i++) {
        f[i] = f[i - 1] + g[i - 1];
    }

    int n;
    while (cin >> n) {
        cout << f[n] << '\n';
    }

    return 0;
}
