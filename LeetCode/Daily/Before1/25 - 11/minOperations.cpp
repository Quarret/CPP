#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int ans = 0;
    vector<int> st;

    for (int x : nums) {
        while (st.size() && x < st.back()) {
            st.pop_back();
            ans++;
        }

        if (st.empty() || x != st.back()) {
            st.push_back(x);
        }
    }
    
    return ans + st.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
