#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size(), t = n;
    int l = 0, r = 0, idx = 0;

    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        idx = i;
        r = nums[idx];

        while (1) {
            if (vis[idx]) break;
            vis[idx] = 1;
            l = r;
            r = nums[(idx + k) % n];
            nums[(idx + k) % n] = l;
            idx = (idx + k) % n;
        }
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[(i + k) % n] = nums[i];
    }

    nums = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
