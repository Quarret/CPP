#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {3,1,5,11,13};
int longestNiceSubarray(vector<int>& nums) {
    int mp[35]{};
    int ans = 0, n = nums.size();

    int flag = 0;
    for (int r = 0, l = 0; r < n; r++) {
        for (int i = 0; i <= 31; i++) {
            if ((nums[r] & (1 << i)) == (1 << i)) {
                mp[i]++;
                if (mp[i] == 2) {
                    flag = 1;
                    //cout << nums[r] << ' ' << flag << '\n';
                }
                
            }
        }

        // 100 001 111 -> 212 不能仅仅只删除一个2就认为任务完成
        while (flag) {
            int flag1 = 0;
            for (int i = 0; i <= 31; i++) {
                if ((nums[l] & (1 << i)) == (1 << i)) {
                    mp[i]--;
                }
                if (mp[i] == 2) flag1 = 1;
            }
            flag = flag1 ? 1 : 0;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}

//位运算代替数组模拟
int longestNiceSubarray(vector<int>& nums) {
    int ans = 0, or_ = 0, n = nums.size();

    for (int l = 0, r = 0; r < n; r++) {
        while (nums[r] & or_) {
            or_ ^= nums[l++];//从集合中删去nums[l]
        }

        or_ |= nums[r];//往集合中加入nums[r]
        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    longestNiceSubarray(nums);

    return 0;
}
