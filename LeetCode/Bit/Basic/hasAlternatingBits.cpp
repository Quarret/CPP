/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 10:25:04
 * @LastEditTime: 2025-07-06 10:30:20
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasAlternatingBits(int n) {
    unsigned int x = n;
    int flag = -1, t = bit_width(x);
    for (int i = 0; i < t; i++) {
        if ((n & (1 << i)) == 1 << i) {
            if (flag == 1) return false;
            else flag = 1;
        } else if ((n & (1 << i)) != 1 << i) {
            if (flag == 0) return false;
            else flag = 0;
        }
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
