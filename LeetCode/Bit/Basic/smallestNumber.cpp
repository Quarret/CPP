/*** 
 * @Author: Quarret
 * @Date: 2025-07-04 16:31:15
 * @LastEditTime: 2025-07-04 16:33:36
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int smallestNumber(int n) {
    int cnt = 0;
    while ((1 << cnt) <= n) cnt++;
    
    return (1 << cnt) - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
