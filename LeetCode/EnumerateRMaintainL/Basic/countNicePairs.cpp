/*** 
 * @Author: Quarret
 * @Date: 2025-05-07 09:17:40
 * @LastEditTime: 2025-06-04 12:24:42
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long MOD = 1e9 + 7;
long long MOD = 1e9 + 7;
/*
未注意两数关系的反转
*/
long long rev(long long x) {
    stack<int> st;
    while (x) {
        st.push(x % 10);
        x /= 10;
    }

    long long times = 1;
    while (!st.empty()) {
        x += times * st.top();
        st.pop();
        times *= 10;
    }

    return x;
}
/*
字符串反转
*/
long long rev1(long long x) {
    string num = to_string(x);
    reverse(num.begin(), num.end());
    x = stol(num);
    return x;
}

/*
最佳反转写法
*/
long long rev2(long long x) {
    long long num = 0;
    while (x) {
        int num1 = x % 10;
        num = num * 10 + num1;
        x /= 10;
    }

    return num;
}
int countNicePairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<long long, long long> mp;
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int revx = rev2(nums[i]);
        ans = (ans + mp[nums[i] - revx]) % MOD;//迭代不变量

        mp[nums[i] - revx]++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
