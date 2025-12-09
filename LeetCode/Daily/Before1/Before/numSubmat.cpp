#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector sum(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int r = 0; r < m - i; r++) {
                int left = -1, right = n - j, mid = 0;
                while (left + 1 < right) {
                    int mid = left + (right -left) / 2;
                    if (sum[i + r + 1][j + mid + 1] - sum[i + r + 1][j] - sum[i][j + mid + 1] + sum[i][j] == (r + 1) * (mid + 1)) left = mid;
                    else right = mid;
                }
                ans += left + 1;
            }
        }
    }

    return ans;
}

//统计 a 的全 h 子数组的数目
int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), ans = 0;

    for (int top = 0; top < m; top++) {
        vector<int> a(n);
        for (int bottom = top; bottom < m; bottom++) {
            int h = bottom - top + 1;
            int l = -1;
            for (int r = 0; r < n; r++) {
                a[r] += mat[bottom][r];
                if (a[r] == h) ans += r - l + 1; //sliding windows that more smaller more corret
                else l = r;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
