#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int pre = 0, num = (1 << maximumBit) - 1;
    vector<int> ans;
    for (int x: nums) pre ^= x;
    
    while (nums.size()) {
        ans.push_back(pre ^ num);//低n位取反
        pre ^= nums.back();
        nums.pop_back();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
