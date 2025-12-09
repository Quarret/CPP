#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if ((nums[i] + n)% n == 0) continue;
        int slow = i, fast = i;
        int flag0 = 0, flag1 = 0;
        while (1) {
            if (nums[slow] < 0) flag0 = 1;
            else flag1 = 1;
            slow = ((slow + nums[slow]) % n + n) % n;

            if (nums[fast] < 0) flag0 = 1;
            else flag1 = 1;
            fast = ((fast + nums[fast]) % n + n) % n;
            
            if (nums[fast] < 0) flag0 = 1;
            else flag1 = 1;
            fast = ((fast + nums[fast]) % n + n) % n;

            if (nums[fast] % n == 0 || (flag0 && flag1)) break;

            if (slow == fast) return true;
        }
    }
    
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
