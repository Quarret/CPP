#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestBalanced(vector<int>& nums) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        unordered_set<int> st1, st2;
        for (int j = i; j < n; j++) {
            int x = nums[j];
            (x % 2) ? st1.insert(x) : st2.insert(x);

            if (st1.size() == st2.size()) ans = max(ans, j - i + 1);
        }
    }

    return ans;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
