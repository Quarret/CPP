#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector f(101, vector<double>(101, 0));
    
    f[0][0] = 1.0 * poured;
    for (int i = 0; i < query_row; i++) {
        for (int j = 0; j <= i; j++) {
            if (f[i][j] > 1.0) {
                double half = (f[i][j] - 1.0) / 2.0;
                f[i][j] = 1;
                f[i + 1][j] += half;
                f[i + 1][j + 1] += half;
            }
        }
    }

    return f[query_row][query_glass];
}

// 滚动数组
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> cur = {1.0 * poured};

    for (int i = 1; i <= query_row; i++) {
        vector<double> nxt(i + 1, 0.0);
        for (int j = 0; j < cur.size(); j++) {
            double half = (cur[j] - 1.0) / 2.0;
            if (half > 0) {
                nxt[j] += half;
                nxt[j + 1] += half;
            }
        }

        cur = move(nxt);
    }

    return min(cur[query_glass], 1.0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}