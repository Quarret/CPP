#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    int m = rectangles.size();
    int cnt1 = 0, cnt2 = 0;
    
    int x_end = -1, y_end = -1;
    ranges::sort(rectangles, {}, [](auto &mat) {
        return mat[0];
    });
    for (auto &mat: rectangles) {
        int x1 = mat[0];
        int x2 = mat[2];

        if (x1 >= x_end) {
            cnt1++;
        }
        x_end = max(x_end, x2);
    }

    ranges::sort(rectangles, {}, [](auto &mat) {
        return mat[1];
    });
    for (auto &mat: rectangles) {
        int y1 = mat[1];
        int y2 = mat[3];

        if (y1 >= y_end) {
            cnt2++;
        }
        y_end = max(y_end, y2);
    }

    return cnt1 >= 3 || cnt2 >= 3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
