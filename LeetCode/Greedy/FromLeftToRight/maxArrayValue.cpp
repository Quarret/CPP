#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxArrayValue(vector<int>& nums) {
    long long ans = nums.back(), n = nums.size();
    
    vector<long long> a(nums.begin(), nums.end());
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) {
            a[i] += a[i + 1];
        }
        ans = max(ans, a[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
