#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    vector<int> diff(days + 1);
    for (auto &p : meetings) {
        diff[p[0] - 1]++;
        diff[p[1]]--;
    }
    
    int sum_d = 0, ans = 0;
    for (int i = 0; i < days; i++) {
        sum_d += diff[i];
        ans += sum_d == 0;
    }

    return ans;
}

int countDays(int days, vector<vector<int>>& meetings) {
    ranges::sort(meetings, {}, [](auto &p) {
        return p[0];
    });

    int pre_l = 1, pre_r = 0;
    for (auto &p : meetings) {
        int l = p[0], r = p[1];
        if (l > pre_r) {
            days -= pre_r - pre_l + 1;
            pre_l = l;
            pre_r = r;
        } else {
            pre_r = max(pre_r, r);
        }
    }

    days -= pre_r - pre_l + 1;
    return days;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
