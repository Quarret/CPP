#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
从前往后遍历 + 需要考虑相邻元素 + 有消除操作 = 栈
*/
int minDeletion(vector<int>& nums) {
    int n = nums.size(), m, ans = 0;
    stack<int> st;


    for (int i = 0; i < n; i++) {
        m = st.size();
        if (m % 2 == 1) {
            if (nums[i] != st.top()) st.push(nums[i]);
            else ans++;
        }
        else st.push(nums[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
