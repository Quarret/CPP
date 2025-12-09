#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = 1e9, r = 0, mid = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, *max_element(matrix[i].begin(), matrix[i].end()));
        l = min(l, *min_element(matrix[i].begin(), matrix[i].end()));
    }
    l--;
    r++;
    
    auto check = [&](int x) -> bool {
        int cnt = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            idx = lower_bound(matrix[i].begin(), matrix[i].end(), x + 1) - matrix[i].begin();
            cnt += idx;

            if (cnt >= k) return 1;
        }
        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
