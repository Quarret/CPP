#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 由于最大矩阵中的高度一定是 heights 中的高度
// 视每个高度为矩形中的最小高度
// 两次遍历用单调栈维护每个高度左右两侧第一个比他小的高度的下标
// 最后一次遍历计算答案
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    
    vector<int> st;
    vector<int> left(n, -1);
    for (int i = 0; i < n; i++) {
        int h = heights[i];
        while (!st.empty() && heights[st.back()] >= h) {
            st.pop_back();
        }

        if (!st.empty()) {
            left[i] = st.back();
        }
        st.push_back(i);
    }

    st.clear();
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        int h = heights[i];
        while (!st.empty() && heights[st.back()] >= h) {
            st.pop_back();
        }

        if (!st.empty()) {
            right[i] = st.back();
        }
        st.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
}

// 找点 单调栈 教学视频看看
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    
    vector<int> st;
    vector<int> left(n, -1);
    vector<int> right(n, n); // 定义 right[i] 为 i 右侧第一个小于等于 h[i] 的下标
    for (int i = 0; i < n; i++) {
        int h = heights[i];
        while (!st.empty() && heights[st.back()] >= h) {
            right[st.back()] = i;
            st.pop_back();
        }

        if (!st.empty()) {
            left[i] = st.back();
        }
        st.push_back(i);
    } 

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << heights[i] << ' ' << right[i] << ' ' << left[i] << '\n';
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}