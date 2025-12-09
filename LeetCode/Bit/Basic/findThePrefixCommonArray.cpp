/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 10:37:17
 * @LastEditTime: 2025-07-06 10:49:06
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    long long n = A.size(), prea = 0, preb = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        prea |= 1LL << A[i];
        preb |= 1LL << B[i];

        ans[i] = __builtin_popcountll(prea & preb);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
