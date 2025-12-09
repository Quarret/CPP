#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> dist = {1,1,100000};
int minSpeedOnTime(vector<int>& dist, double hour) {
    int n = dist.size();
    if (hour <= n - 1) return - 1;

    int l = 1, maxx = *max_element(dist.begin(), dist.end()), r = max(maxx, dist.back() * 100), mid = 0;

    auto check = [&](int k) -> bool {
        double ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += (dist[i] + k - 1) / k;
        }
        ans += (double)dist.back() / (double)k;

        return ans <= hour;
    };

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (!check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    int l = -1, r = nums.size(), mid = 0;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] >= 0) r = mid;
        else l = mid;  
    }

    cout << r;

    return 0;
}
