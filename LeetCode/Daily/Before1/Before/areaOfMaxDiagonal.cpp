#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int maxx = 0, ans = 0;
    for (auto &e : dimensions) {
        int x = e[0], y = e[1];
        if (x * x + y * y > maxx) {
            maxx = x * x + y * y;
            ans = x * y;
        } else if (x * x + y * y == maxx) {
            ans = max(ans, x * y);
        } 
    }

    return ans;
}

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    pair<int, int> mx{};

    for (auto &e : dimensions) {
        int x = e[0], y = e[1];
        mx = max(mx, pair(x * x + y * y, x * y));//two keywords
    }

    return mx.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
