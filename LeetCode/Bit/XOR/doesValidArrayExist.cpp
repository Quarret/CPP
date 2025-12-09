/*** 
 * @Author: Quarret
 * @Date: 2025-07-08 08:05:05
 * @LastEditTime: 2025-07-08 12:54:45
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    vector<int> ans1, ans2;
    int n = derived.size();
    ans1.push_back(0);
    ans2.push_back(1);

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            ans1.push_back(derived[i] ^ ans1[0]);
            ans2.push_back(derived[i] ^ ans2[0]);
        }
        else {
            ans1.push_back(derived[i] ^ ans1.back());
            ans2.push_back(derived[i] ^ ans2.back());
        }
    }

    if (ans1.back() == ans1[n - 1]) return true;
    if (ans2.back() == ans2[n - 1]) return true;
    return false;
}

/*

123
推公式
a ^ b = c
a ^ a ^ b = a ^ c
0 ^ b = a ^ c// 0异或任何数，值都不变
b = a ^ c

ori[n - 1] = ori[0] * der[1] * ... * der[n - 2]
ori[0] * ori[n - 1] = der[n - 1]
联立得
der[0] * .. * der[n - 1] = 0
*/

bool doesValidArrayExist(vector<int>& derived) {
    int cnt = 1;

    for (auto& x: derived) {
        cnt ^= x;
    }

    return cnt == 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
