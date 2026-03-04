#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    ranges::sort(hBars);
    ranges::sort(vBars);

    int pre_r = -1, pre_c = -1, cur_r = 0, cur_c = 0; 
    int r_mx = 0, c_mx = 0;
    for (int x : hBars) {
        if (x == 1 || x == n + 2) continue;
        if (x == pre_r + 1) {
            cur_r++;
        } else {
            cur_r = 1;
        }
        pre_r = x;     
        r_mx = max(r_mx, cur_r);
    }

    for (int y : vBars) {
        if (y == 1 || y == m + 2) continue;
        if (y == pre_c + 1) {
            cur_c++;
        } else {
            cur_c = 1;
        }
        pre_c = y;     
        c_mx = max(c_mx, cur_c);
    }

    int mn = min(c_mx, r_mx);
    return (mn + 1) * (mn + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}