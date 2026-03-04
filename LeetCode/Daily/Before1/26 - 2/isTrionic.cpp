#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isTrionic(vector<int>& nums) {
    int n = nums.size();

    for (int p = 1; p < n - 2; p++) {
        for (int q = p + 1; q < n - 1; q++) {
            int ok = 1;

            for (int i = 0; i < p; i++) {
                if (nums[i] >= nums[i + 1]) {
                    ok = 0;
                    break;
                }
            }

            for (int i = p; i < q; i++) {
                if (nums[i] <= nums[i + 1]) {
                    ok = 0;
                    break;
                }
            }

            for (int i = q; i < n - 1; i++) {
                if (nums[i] >= nums[i + 1]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) return true;
        }
    }

    return false;
}


// O(n) 分组循环
bool isTrionic(vector<int>& nums) {
    int n = nums.size();

    // 第一段
    int i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    if (i == 1) return false;

    // 第二段
    int i0 = i;
    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    if (i == i0 || i == n) {
        return false;
    }

    // 第三段
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    
    return i == n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}