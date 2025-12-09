#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumEffort(vector<vector<int>>& tasks) {
    int n = tasks.size();
    sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b) {
        if (a[1] - a[0] > b[1] - b[0]) return true;
        else if (a[1] - a[0] == b[1] - b[0]) {
            return a[1] > b[1];
        }

        return false;
    });
    
    auto check = [&](int x) -> bool {
        for (int i = 0; i < n; i++) {
            if (x < tasks[i][1]) {
                return false;
            }
            x -= tasks[i][0];
        }

        return true;
    };

    int l = 0, r = 1e9 + 5;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
