#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<long long> mergeAdjacent(vector<int>& nums) {
    using ll = long long;
    vector<ll> st;

    for (int x : nums) {
        ll s = x;
        while (!st.empty() && s == st.back()) {
            s += st.back();
            st.pop_back();
        }
        st.push_back(s);
    }

    return st;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}