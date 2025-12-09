#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> ans1(n, -1), ans2(m, - 1);
    unordered_map<int, int> idx;
    stack<int> st;
    
    for (int i = 0; i < m; i++) {
        idx[nums2[i]] = i;
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
            ans2[st.top()] = nums2[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        int t = nums2[i];
        ans1[i] = ans2[idx[t]];
    }

    return ans1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
