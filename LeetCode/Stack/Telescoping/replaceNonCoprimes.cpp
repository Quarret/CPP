#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> replaceNonCoprimes(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || gcd(nums[i], st.top()) == 1) st.push(nums[i]);
        else {
            int gcd1 = gcd(nums[i], st.top()), lcm1 = nums[i];
    
            while (!st.empty() && gcd1 != 1) {
                lcm1 = 1LL * lcm1 * st.top() / gcd1;
                st.pop();
                if (!st.empty())  gcd1 = gcd(lcm1, st.top());
            }

            st.push(lcm1);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();   
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

/*
灵神思路:
用vector来模拟栈
vec拥有栈的push与pop的操作，并且可以idx指定元素,比栈更优
*/

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

    vector<int> nums = {6,4,3,2,7,6,2};
    replaceNonCoprimes(nums);

    return 0;
}
