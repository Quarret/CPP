/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 11:43:35
 * @LastEditTime: 2025-07-06 11:46:24
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> evenOddBit(int n) {
    int t = __bit_width(n);
    int even = 0, odd = 0;

    for (int i = 0; i < t; i++) {
        if ((n >> i) & 1) {
            if (i % 2) odd++;
            else even++;
        }
    }

    return {even, odd};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
