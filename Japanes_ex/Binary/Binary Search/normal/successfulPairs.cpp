/*** 
 * @Author: Quarret
 * @Date: 2025-04-16 09:16:37
 * @LastEditTime: 2025-06-06 00:05:10
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
a / b 向上取整 == (a + b - 1) / b 向下取整 == (a - 1) / b 向下取整 + 1 
*/
int check(vector<int>& potions, long long k) {
    long long l = 0, r = potions.size() - 1, mid = 0;
    
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (potions[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        int n = spells.size(), m = potions.size();
        for (int i = 0; i < n; i++) {
            ans.push_back(m - check(potions, (success - 1) / spells[i] + 1));
            //ans.push_back(m - check(potions, ceil((double)success / (double)spells[i])));
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
