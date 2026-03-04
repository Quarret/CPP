#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    
    vector<int> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.back()] < temperatures[i]) {
            ans[st.back()] = i - st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}