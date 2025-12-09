#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    int s = 0, num1 = INT_MAX, num2 = INT_MAX;
    vector<int> a, b;
    for (int x : nums) {
        s += x;
        if (x % 3 == 1) {
            num1 = min(num1, x);
            a.push_back(x);
        } else if (x % 3 == 2) {
            num2 = min(num2, x);
            b.push_back(x);
        }
    }
    
    if (s % 3 == 0) {
        return s;
    }

    ranges::sort(a);
    ranges::sort(b);

    if (s % 3 == 1) {
        return b.size() >= 2 ? max(s - num1, s - b[0] - b[1]) : s - num1;
    } else if (s % 3 == 2) {
        return a.size() >= 2 ? max(s - num2, s - a[0] - a[1]) : s - num2;
    }

    return s;
}

int maxSumDivThree(vector<int>& nums) {
    int n = nums.size();
    vector memo(n, vector<int>(3, -1));


    auto dfs = [&](this auto&& dfs, int i, int MOD) -> int {
        if (i < 0) {
            return MOD ? INT_MIN : 0;
        }

        int &res = memo[i][MOD];
        if (res != -1) {
            return res;
        }
        res = max(dfs(i - 1, MOD), dfs(i - 1, (MOD + nums[i]) % 3) + nums[i]);

        return res;
    };

    return dfs(n - 1, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
