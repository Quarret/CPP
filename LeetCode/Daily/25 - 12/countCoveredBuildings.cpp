#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int countCoveredBuildings(int n, vector<vector<int>> &buildings)
{
    vector<array<int, 2>> row(n + 1, {INT_MAX, INT_MIN}), col(n + 1, {INT_MAX, INT_MIN});
    for (auto &p : buildings)
    {
        int r = p[0], c = p[1];
        row[r][0] = min(row[r][0], c);
        row[r][1] = max(row[r][1], c);

        col[c][0] = min(col[c][0], r);
        col[c][1] = max(col[c][1], r);
    }

    int ans = 0;
    for (auto &p : buildings)
    {
        int r = p[0], c = p[1];
        if (row[r][0] == c || row[r][1] == c)
            continue;
        if (col[c][0] == r || col[c][1] == r)
            continue;
        ans++;
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
