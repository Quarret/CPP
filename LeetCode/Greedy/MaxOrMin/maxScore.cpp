#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxScore(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater());
    
    int ans = 0, pre = 0;
    for (int x : nums) {
        pre += x;
        ans += pre > 0;
        if (pre <= 0) break;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
