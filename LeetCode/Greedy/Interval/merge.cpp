#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    ranges::sort(intervals, {}, [&](auto &p)
                 { return p[0]; });

    vector<vector<int>> ans;
    int l = intervals[0][0], r = intervals[0][1];
    for (auto &p : intervals)
    {
        if (p[0] > r)
        {
            ans.push_back({l, r});
            l = p[0];
            r = p[1];
            continue;
        }

        l = p[0];
        r = max(p[1], r);
    }
    ans.push_back({l, r});

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
