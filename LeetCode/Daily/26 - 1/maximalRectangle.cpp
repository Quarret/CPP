#include <bits/stdc++.h>
using ll = long long;
using namespace std;

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

// 降维思想: 选取某一行做底
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix[0].size();
    vector<int> height(n);
    
    int mx = 0;
    for (auto s : matrix) {
        for (int j = 0; j < n; j++) {
            if (s[j] != '0') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        mx = max(mx, largestRectangleArea(height));
    }

    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}