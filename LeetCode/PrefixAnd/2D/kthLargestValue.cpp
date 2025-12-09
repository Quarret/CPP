/*** 
 * @Author: Quarret
 * @Date: 2025-06-15 16:21:38
 * @LastEditTime: 2025-06-15 16:38:48
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prexor(m + 1, vector<int>(n + 1, 0));
    vector<int> arr;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prexor[i + 1][j + 1] = prexor[i + 1][j] ^ prexor[i][j + 1] ^ prexor[i][j] ^ matrix[i][j];
            arr.push_back(prexor[i + 1][j + 1]);
        }
    }

    sort(arr.begin(), arr.end(), greater());
    return arr[k - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
