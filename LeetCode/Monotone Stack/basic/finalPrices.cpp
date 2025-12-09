#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(prices.begin(), prices.end());
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[i] <= prices[st.top()]) {
            ans[st.top()] = ans[st.top()] - prices[i];
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
