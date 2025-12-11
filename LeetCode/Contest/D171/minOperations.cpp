#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> minOperations(vector<int>& nums) {
    int n = nums.size();
    auto to_binary = [&](int x) -> string {
        string s = "";
        while (x) {
            s.insert(0, 1, (x & 1) + '0');
            x >>= 1;
        }
        return s;
    };

    auto isReverse = [&](string s) -> bool {
        int m = s.size();
        int i = 0, j = m - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    };

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int x1 = x, x2 = x;
        int ans1 = INT_MAX, ans2 = INT_MAX;
        while (1) {
            string s = to_binary(x1);
            if (isReverse(s)) {
                ans1 = x1 - x;
                break;
            }
            x1++;      
        }

        while (1) {
            string s = to_binary(x2);
            if (isReverse(s)) {
                ans2 = x - 2;
                break;
            }
            x2--;
        }
        ans[i] = min(ans1, ans2);
    }
    return ans;        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
