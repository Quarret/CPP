/*** 
 * @Author: Quarret
 * @Date: 2025-07-08 07:57:19
 * @LastEditTime: 2025-07-08 12:54:02
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size(), m = queries.size();
    vector<int> pre(n + 1, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] ^ arr[i];
    
    for (auto& arr: queries) {
        int l = arr[0], r = arr[1];
        ans.push_back(pre[r + 1] ^ pre[l]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
