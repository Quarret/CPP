#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int cnt = 0, n = nums.size();
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if ((nums[i] ^ (cnt % 2)) == 0) {
            ans++;
            cnt++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
