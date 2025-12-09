/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 09:28:08
 * @LastEditTime: 2025-07-06 09:43:46
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int bitwiseComplement(int n) {
    unsigned int x = n;
    //注意bitwidth(0) == 0
    return n ? n ^ ((1 << (bit_width(x))) - 1) : 0;        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
