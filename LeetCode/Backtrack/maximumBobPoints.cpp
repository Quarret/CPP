#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    int maxx = 0, n = aliceArrows.size();
    vector<int> path(n), ans;
    auto dfs = [&](this auto&& dfs, int i, int rest, int score) -> void {
        if (i == n - 1) {
            score += (rest > aliceArrows[i] ? i : 0);
            path[i] = rest;
            if (score > maxx) {
                maxx = score;
                ans = path;
            }
            return;
        }

        if (rest > aliceArrows[i]) {
            path[i] = aliceArrows[i] + 1;
            dfs(i + 1, rest - aliceArrows[i] - 1, score + i);
        }

        path[i] = 0;
        dfs(i + 1, rest, score);
    };
    
    dfs(0, numArrows, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
