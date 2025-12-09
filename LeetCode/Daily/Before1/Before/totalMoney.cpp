#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int totalMoney(int n) {
    int tot = 0, x = n;
    for (int base = 0; base < (n + 6) / 7; base++) {
        for (int i = 1; i <= min(x, 7); i++) {
            tot += i + base;
        }

        if (x > 7) x -= 7;
        else return tot;
    }
    
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
