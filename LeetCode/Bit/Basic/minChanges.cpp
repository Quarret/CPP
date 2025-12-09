/*** 
 * @Author: Quarret
 * @Date: 2025-07-05 19:07:56
 * @LastEditTime: 2025-07-05 19:26:45
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minChanges(int n, int k) {
    int num1 = 0, num2 = 0, cnt = 0;
    while (n | k) {
        num1 = n % 2;
        num2 = k % 2;

        if (num1 == 1 && num2 == 0) cnt++;
        else if (num1 == 0 && num2 == 1) return -1;

        n /= 2;
        k /= 2;
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
// 13517237337
