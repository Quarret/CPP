/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 08:56:27
 * @LastEditTime: 2025-07-06 09:11:09
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfSteps(int num) {
    //int cnt = __builtin_popcount(num);
    // while (num) {
    //     cnt++;
    //     cnt /= 2;
    // }

    // return cnt ? cnt - 1 : cnt;          
    
    unsigned x = num;
    return  x ? __builtin_popcount(x) + bit_width(x) - 1 : 0;//最后为1时减一就为0，再加一位重复了
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
