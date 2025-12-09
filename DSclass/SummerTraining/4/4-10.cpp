#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, num, num1;
    cin >> n;
   
    for (int i = 1; i <= n; i++) {
        num1 = i;
        if (num1 % 7 == 0) {
            cout << num1 << '\n';
            continue;
        }

        while (num1) {
            num = num1 % 10;
            num1 /= 10;
            if (num == 7) {
                cout << i << '\n';
                break;
            }
        }

        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
