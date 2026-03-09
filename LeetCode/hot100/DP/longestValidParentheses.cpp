#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // 虚拟红线
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') { // 炸弹
            st.push(i); // 记录下标
        } else if (st.size() > 1) { // 栈顶是炸弹
            st.pop(); // 拆弹
            ans = max(ans, i - st.top()); // 右端点为 i 时, 左端点最小为 红线(st.top()) + 1
        } else { // 剩余的拆弹器 --- 红线
            st.top() = i;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}