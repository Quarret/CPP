#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < k) l = mid + 1;
        else r= mid - 1;
    }

    return l;
}

vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
    int n = increase.size(), m = requirements.size(), num1 = 0, num2 = 0, num3 = 0;
    vector<int> C(n + 1, 0), R(n + 1, 0), H(n + 1, 0), ans(m, 0);

    for (int i = 0; i < n; i++) {
        C[i + 1] = C[i] + increase[i][0];
        R[i + 1] = R[i] + increase[i][1];
        H[i + 1] = H[i] + increase[i][2];
    }

    for (int i = 0; i < m; i++) {
        num1 = check(C, requirements[i][0]);
        num2 = check(R, requirements[i][1]);
        num3 = check(H, requirements[i][2]);
        int num4 = max(num1, max(num2, num3));

        ans[i] = num4 == n + 1 ? -1 : num4;
    }

    return ans; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
