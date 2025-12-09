/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 09:12:06
 * @LastEditTime: 2025-07-06 09:23:23
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findComplement(int num) {
    unsigned int x = num;
    int cnt = bit_width(x);

    int ans = 0;
    for (int i = 0; i <= cnt; i++) {
        if ((num & (1 << i)) != (1 << i)) ans += 1 << i;
    }        

    return ans;

    //O(1)
    return num ^ ((1 << (__bit_width(num))) - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
