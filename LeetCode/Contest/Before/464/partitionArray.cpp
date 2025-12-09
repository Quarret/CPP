#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    int m = n / k;
    if (n % k != 0) return false;

    unordered_map<int, int> cnt;
    for (int x : nums) {
        cnt[x]++;
        if (cnt[x] > m) return false;
    }

    return true;
}

// 选 k 个不同整数一组
// n - m >= (k - 1) * m
bool partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n % k) return false;

    unordered_map<int, int> cnt;
    int m = 0;
    for (int x : nums) {
        cnt[x]++;
        m = max(m, cnt[x]);
    }

    return m <= n / k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
