#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 0LL) < 0) {
        return -1;
    }
    
    int ans = 0;
    long long hp = 1;
    priority_queue<int> h; // 大根堆
    for (int x : nums) {
        if (x < 0) {
            h.push(-x);
        }

        hp += x;
        // 保证堆顶 >= -x
        if (hp < 1) {
            // 反悔, 加上之前减去的最大值
            hp += h.top();
            h.pop();
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
