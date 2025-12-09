#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minLengthAfterRemovals(vector<int>& nums) {
    int max_cnt = 0, n = nums.size();
    unordered_map<int, int> cnt;
    for (int x : nums) {
        cnt[x]++;
        max_cnt = max(max_cnt, cnt[x]);
    }

    if (max_cnt >= n - max_cnt) {
        return max_cnt * 2 - n;
    } else {
        return n % 2;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
