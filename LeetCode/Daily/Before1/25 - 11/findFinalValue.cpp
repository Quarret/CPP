#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> st;
    for (int x : nums) {
        st.insert(x);
    }
    
    while (st.contains(original)) {
        original <<= 1;
    }

    return original;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
