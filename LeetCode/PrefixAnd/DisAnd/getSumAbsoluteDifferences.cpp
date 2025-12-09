/*** 
 * @Author: Quarret
 * @Date: 2025-06-05 17:58:19
 * @LastEditTime: 2025-06-05 18:04:24
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
    
    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(i * nums[i] - pre[i] + pre[n] - pre[i] - nums[i] * (n - i));
    }

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
