#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double separateSquares(vector<vector<int>>& squares) {
    long long tot_area = 0;
    int max_y = 0;
    for (auto &s : squares) {
        int l = s[2];
        tot_area += 1.0 * l * l;
        max_y = max(max_y, s[1] + l);
    }

    auto check = [&](double y) -> bool {
        double area = 0;
        for (auto &s : squares) {
            double yi = s[1];
            if (yi < y) {
                double l = s[2];
                area += l * min(y - yi, l);
            }
        }

        return 2 * area >= tot_area; 
    };

    double left = 0, right = max_y;
    // 二分 47 次差不多到达精确度
    for (int i = 0; i < 47; i++) {
        double mid = left + (right - left) / 2;
        (check(mid) ? right : left) = mid;
    }

    // 中点误差小
    return (left + right) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}