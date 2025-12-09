#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int ok = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != nums[i + 1]) ok = 1;
    }

    return ok;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
