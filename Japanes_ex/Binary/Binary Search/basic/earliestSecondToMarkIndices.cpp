#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
    long long n = nums.size(), m = changeIndices.size(), r = m, l = 0, mid = 0;
    unordered_map<long long, long long> mp;

    for (int i = 0; i < n; i++) {
        l += nums[i] + 1;
        mp[i + 1] = nums[i];
    }

    auto check = [&](long long t) -> bool {
        vector<int> pos, val;
        unordered_map<long long, long long> mp1;
        for (int i = t - 1; i >= 0; i--) {
            if (!mp1[changeIndices[i]]) {
                mp1[changeIndices[i]] = 1;
                pos.push_back(i);
                val.push_back(mp[changeIndices[i]]);
            }
        }

        long long k = pos.size(), num = 0;

        if (k != n) return 0;

        reverse(pos.begin(), pos.end());
        reverse(val.begin(), val.end());

        
        for (int i = 0; i < k; i++) {
            if (pos[i] - num >= val[i]) {
                num += val[i] + 1;
            } else return 0;
        }

        return 1;
    };
    
    /*
    灵神写法
    不断更新需要考试的科目以及需要复习的时间
    */
    
    vector<int> vis(n, 0);
    auto check2 = [&](int t) -> bool {
        int exam = n, study = 0;
        for (int i = t - 1; i >= 0 && study <= i + 1; i--) {//复习的天数不能大于剩下的时间
            int idx = changeIndices[i] - 1;
            if (vis[idx] != t) {// 首次遇到考试，直接提前预支复习时间
                vis[idx] = t;// 每次二分的中间值不同，多次复用数组
                exam--;
                study += nums[idx];
            } else if (study) {//如果需要学习
                study--;
            }
        }

        return exam == 0 && study == 0;
    };   

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (!check2(mid)) l = mid + 1;
        else r = mid - 1;
    }

    return (l >= m + 1 ? -1 : l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
