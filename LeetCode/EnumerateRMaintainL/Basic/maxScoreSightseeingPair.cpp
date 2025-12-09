/*** 
 * @Author: Quarret
 * @Date: 2025-05-07 09:10:35
 * @LastEditTime: 2025-06-04 12:22:21
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int maxx = values[0], ans = -1e9;

    for (int i = 1; i < n; i++) {
        ans = max(ans, maxx + values[i] - i);//迭代不变量1
        maxx = max(maxx, values[i] + i);//迭代不变量2
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
