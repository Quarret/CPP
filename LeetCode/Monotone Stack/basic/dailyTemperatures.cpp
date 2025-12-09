#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
1 4 3 5 5 2 3 6
从右往左遍历
6 右侧无数据直接入栈
3 比6小
2 比2小
5 比2大，2出栈，比3大，3出栈，比六小，入栈
这里2，3都出栈是因为再往前遍历，前面数比他们小的第一个大数一定是5，比他们大的答案也不会是它们
5 与5相等，显然最左的5更满足题目要求
...

栈中的单调性要与题目要求的 数第一个右侧大数对应
及时去掉无用数
*/
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = ans[st.top()] - i; 
        st.push(i);
    }

    return ans;
}

/*
从左到右遍历
当数字大于栈顶元素，计算答案，出栈，入栈未得到答案的数
栈中存放的都是未得到答案的数
*/
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            ans[st.top()] = i - st.top();// 题目要算的在while中计算
            st.pop(); 
        }
        st.push(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
