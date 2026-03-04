#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> st;
    vector<int> left(n, -1);
    vector<int> right(n, n);
    for (int i = 0; i < n; i++)
    {
        int h = heights[i];
        while (!st.empty() && heights[st.back()] >= h)
        {
            right[st.back()] = i;
            st.pop_back();
        }

        if (!st.empty())
        {
            left[i] = st.back();
        }
        st.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}