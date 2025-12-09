/*** 
 * @Author: Quarret
 * @Date: 2025-05-07 09:43:17
 * @LastEditTime: 2025-06-04 11:48:48
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    vector<int> premin(n, 0), premax(n, 0), preminidx(n, 0), premaxidx(n, 0);
    vector<int> sufmin(n, 0), sufmax(n, 0), sufminidx(n, 0), sufmaxidx(n, 0);

    int minn = 1e9, maxx = -1, minidx = 0, maxidx = 0;
    for (int i = 0; i < n; i++) {
        if (minn > nums[i]) minidx = i;
        preminidx[i] = minidx;

        if (maxx < nums[i]) maxidx = i;
        premaxidx[i] = maxidx;

        minn = min(minn, nums[i]);
        maxx = max(maxx, nums[i]);
        premin[i] = minn;
        premax[i] = maxx;
    }

    minn = 1e9, maxx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (minn > nums[i]) minidx = i;
        sufminidx[i] = minidx;

        if (maxx < nums[i]) maxidx = i;
        sufmaxidx[i] = maxidx;

        minn = min(minn, nums[i]);
        maxx = max(maxx, nums[i]);
        sufmin[i] = minn;
        sufmax[i] = maxx;
    }

    for (int i = 0; i < n; i++) {
        int idx1 = i - indexDifference, idx2 = i + indexDifference;

        if (idx1 >= 0) {
            if (premin[idx1] <= nums[i] - valueDifference) return {preminidx[idx1], i};
            else if (premax[idx1] >= nums[i] + valueDifference) return {premaxidx[idx1], i};
        } else if (idx2 <= n - 1) {
            if (sufmin[idx2] <= nums[i] - valueDifference) return {sufminidx[idx2], i};
            else if (sufmax[idx2] >= nums[i] + valueDifference) return {sufmaxidx[idx2], i};
        }
    }

    return {-1, -1};
}

/*
不必维护后缀
假设 {1, 3} {3, 4}都符合
遍历j(假设j在i右侧),遍历到3和遍历到4就都遍历到了
*/

vector<int> nums = {3,12,40};
vector<int> findIndices1(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    int minn = 1e9, maxx = -1, minidx = 0, maxidx = 0;

    for (int j = indexDifference; j < n; j++) {
        //遍历j更新前j - va
        int i = j - indexDifference;
        if (nums[i] > maxx) {
            maxx = nums[i];
            maxidx = i;
        }
        if (nums[i] < minn) {
            minn = nums[i];
            minidx = i;
        } 

        if (maxx >= nums[j] + valueDifference) return {maxidx, j};
        else if (minn <= nums[j] - valueDifference) return {minidx, j};

        
    }

    return {-1, -1};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    findIndices1(nums, 0, 9);

    return 0;
}
