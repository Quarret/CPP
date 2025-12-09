#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int x = 1, y = 1;
    bool left = 1, down = 0;
    while (1) {
        if (x > n || y > n) {
            break;
        }

        cout << x << ' ' << y << '\n';
        k--;

        if (left == 1) {
            y += 1;
            left = 0;
            down = 1;
        } else if (down == 1) {
            x += 1;
            left = 1;
            down = 0;
        }
    }

    int t = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - t; j++) {
            if (!k) {
                break;
            } 
            cout << i << ' ' << j << '\n';
            k--;
        }
        if (!k) {
            break;
        }
        t++;
    }

    t = 1;
    int h = 3;
    for (int i = 1; i <= n; i++) {
        for (int j = h; j <= n; j++) {
            if (!k) {
                break;
            }

            cout << i << ' ' << j << '\n';
            k--;
        }
        if (!k) {
            break;
        }
        t++;
        h++;
    }

    return 0;
}
