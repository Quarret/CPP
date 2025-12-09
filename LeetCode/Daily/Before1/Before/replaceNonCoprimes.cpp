#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> replaceNonCoprimes(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(nums[i]);

        while (ans.size() > 1) {
            int x = ans.back(), y = ans[ans.size() - 2];
            int g = gcd(x, y);
            if (g == 1) break;
            ans.pop_back();
            ans.back() *= x / g;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
