/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 08:46:15
 * @LastEditTime: 2025-07-06 08:50:38
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int hammingDistance(int x, int y) {
    long long cnt = 0;
    while (x | y) {
        int num1 = x % 2, num2 = y % 2;
        if (num1 != num2) cnt++;
        x /= 2;
        y /= 2;
    }

    return cnt;
}

//位运算
int hammingDistance(int x, int y) {
    long long cnt = 0;
    
    for (int i = 0; i <= 31; i++) {
        if ((x & (1 << i)) != (y & (1 << i))) cnt++;
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
