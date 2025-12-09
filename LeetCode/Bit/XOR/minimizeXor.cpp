/*** 
 * @Author: Quarret
 * @Date: 2025-07-09 08:29:06
 * @LastEditTime: 2025-07-10 07:01:34
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimizeXor(int num1, int num2) {
    int cnt = __builtin_popcount(num2);
    int ans = 0, len = __bit_width(num1);

    for (int i = len - 1; i >= 0; i--) {
        if ((num1 >> i) & 1 == 1) {
            ans += 1 << i;
            cnt--;
        }

        if (!cnt) break;
    }

    if (!cnt) return ans;
    int wid = 0;
    while (cnt) {
        if (((1 << wid) & num1) != (1 << wid)) {
            cnt--;
            ans += 1 << wid;
        }
        wid++;
    }

    return ans;        
}

/*
灵神做法:
c1, c2为num1, num2的置位数
若c2 < c1 ，则将num1的最小c1 - c2位 1 置 0
若c1 < c2, 则将num1的最小c2 - c1位 0 置 1
*/

int minimizeXor(int num1, int num2) {
    int c1 = __builtin_popcount(num1), c2 = __builtin_popcount(num2);

    for (; c2 < c1; c2++) num1 &= num1 - 1;//将最小的1置0
    for (; c1 < c2; c2--) num1 |= num1 + 1;//将最小对的0置1

    return num1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
