#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
O(n ^ 3) TLE
*/
int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size(), ans = 0;

    auto check = [&](int i, int j, int k) -> int {
        int dis1 = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
        int dis2 = (points[j][0] - points[k][0]) * (points[j][0] - points[k][0]) + (points[j][1] - points[k][1]) * (points[j][1] - points[k][1]);
        
        if (dis1 == dis2) return 2;
        return 0;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ans += check(i, j, k) + check(j, i, k) + check(i, k, j);
            }
        }
    }

    return ans;
}

/*
灵神思路:
枚举等腰三角形的顶点，记录顶点与其他点的边关系
O(n ^ 2)
*/
int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size(), ans = 0;

    unordered_map<int, int> cnt;

    for (auto& p1: points) {
        cnt.clear();
        for (auto& p2: points) {
            int dis = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            ans += cnt[dis] * 2;
            cnt[dis]++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
