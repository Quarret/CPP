#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), p = 0;
    int pre = -10005, cnt = 0, k = 0;
    for (int x : nums) {
        if (x == pre) cnt++;
        else {
            pre = x;
            cnt = 1;
        }

        if (cnt <= 2) nums[p++] = x;
        else k++;
    }
    
    for (int i = 0; i < k; i++) nums.pop_back();
    return nums.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}