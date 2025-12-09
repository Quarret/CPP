/*** 
 * @Author: Quarret
 * @Date: 2025-06-11 21:35:13
 * @LastEditTime: 2025-06-11 21:37:48
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size(), m = queries.size();;
    vector<int> prexor(n + 1, 0), ans(m, 0);
    for (int i = 0; i < n; i++) prexor[i + 1] = prexor[i] ^ arr[i];

    for (int j = 0; j < m; j++) {
        int l = queries[j][0], r = queries[j][1];
        ans[j] = prexor[r + 1] - prexor[l];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
