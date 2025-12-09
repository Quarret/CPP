#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
        int num1 = a % 2, num2 = b % 2, num3 = c % 2;
        if (num3 == 0 && num1 + num2 != 0) {
            if (num1 == 1 && num2 == 1) ans += 2;
            else ans += 1;
        } else if (num3 == 1 && num1 == 0 && num2 == 0) ans += 1;

        a /= 2, b /= 2, c /= 2;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
