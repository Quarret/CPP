#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int totalWaviness(int num1, int num2) {
    int tot = 0;
    for (int num = num1; num <= num2; num++) {
        int t = num;
        vector<int> nums;
        while (t) {
            nums.push_back(t % 10);
            t /= 10;
        }

        for (int j = 1; j < nums.size() - 1; j++) {
            if (nums[j] > nums[j - 1] && nums[j] > nums[j + 1]) {
                tot++;
            } else if (nums[j] < nums[j - 1] && nums[j] < nums[j + 1]) {
                tot++;
            }
        }
    }
    
    return tot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
