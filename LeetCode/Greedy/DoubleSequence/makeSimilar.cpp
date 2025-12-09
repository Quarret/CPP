#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long makeSimilar(vector<int>& nums, vector<int>& target) {
    vector<int> odd1, even1, odd2, even2;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2) {
            odd1.push_back(nums[i]);
        } else {
            even1.push_back(nums[i]);
        }

        if (target[i] % 2) {
            odd2.push_back(target[i]);
        } else {
            even2.push_back(target[i]);
        }
    }

    ranges::sort(odd1);
    ranges::sort(even1);
    ranges::sort(odd2);
    ranges::sort(even2);

    long long ans = 0;
    int m1 = odd1.size(), m2 = even2.size();
    for (int i = 0; i < m1; i++) {
        if (odd2[i] > odd1[i]) {
            ans += 1LL * (odd2[i] - odd1[i]) / 2;
        } 
    }

    for (int i = 0; i < m2; i++) {
        if (even2[i] > even1[i]) {
            ans += 1LL * (even2[i] - even1[i]) / 2;
        } 
    }

    return ans;
}

long long makeSimilar(vector<int>& nums, vector<int>& target) {
    auto f = [&](vector<int>& a) -> void {
        for (int &x : a) {
            if (x % 2) x = -x;
        }

        sort(a.begin(), a.end());
    };

    f(nums);
    f(target);

    int n = target.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * abs(nums[i] - target[i]);
    }

    return ans / 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
