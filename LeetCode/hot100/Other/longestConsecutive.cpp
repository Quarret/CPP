#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums; 
/*
https://leetcode.cn/problems/longest-consecutive-sequence/solutions/3005726/ha-xi-biao-on-zuo-fa-pythonjavacgojsrust-whop/?envType=study-plan-v2&envId=top-100-liked
任何排序算法的时间都是O(nlogn),所以不能排序
为了达到能够有序遍历判断最长长度，将每个数字的存在信息利用map储存O(nlogn),如果使用unorder_map插入一个pair的时间为O(1)
接着循环遍历map得到最长长度，一定要考虑边界情况，最后的长度也要记录

O(nlogn) + O(n)
*/
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    map<int, bool> mp;

    int ans = 0, maxx = 0, minn = 1e9;
    for (int i = 0; i < n; i++) {
        mp[nums[i]] = true;
        minn = min(minn, nums[i]);
    }

    int num = minn - 1;
    for (auto& it : mp) {
        if (it.first == num + 1) {
            ans++;
            num++;
        } else {
            maxx = max(maxx, ans);
            ans = 1;
            num = it.first;
        }
    }

    maxx = max(maxx, ans);
    return maxx;
}
/*
其实可以不用有序，有序是为了从集合最小点能够逐渐+1遍历，可以直接在hash set(去重)以 O(1) 的时间中来找 x + 1可以实现
但注意优化以x为起始点时，是否存在 x - 1, 因为以 x - 1 的长度必定比x长

有序是为了 x + 1 来查看是否存在该数在集合, 不要过度在意有序， hash set可以 O(1) 查找
*/
int longestConsecutive1(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> st(nums.begin(), nums.end()); // 把 nums 转成哈希集合
    for (int x : st) { // 遍历哈希集合
        if (st.contains(x - 1)) {
            continue;
        }
        // x 是序列的起点
        int y = x + 1;
        while (st.contains(y)) { // 不断查找下一个数是否在哈希集合中
            y++;
        }
        // 循环结束后，y-1 是最后一个在哈希集合中的数
        ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;
    while (cin >> tmp) {
        nums.push_back(tmp);
    }

    cout << longestConsecutive(nums) << '\n';
    return 0;
}
