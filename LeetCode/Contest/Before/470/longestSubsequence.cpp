#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSubsequence(vector<int>& nums) {
    int pre = 0, n = nums.size(), flag = 0;
    for (int x : nums) {
        pre ^= x;
        if (x) flag = 1;
    }
    
    if (pre) return n;
    return flag ? n - 1 : 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
