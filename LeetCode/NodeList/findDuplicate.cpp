#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;

    while (1) {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast) {
            int cur = 0;
            while (slow != cur) {
                slow = nums[slow];
                cur = nums[cur];
            }
            return slow;
        }
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
