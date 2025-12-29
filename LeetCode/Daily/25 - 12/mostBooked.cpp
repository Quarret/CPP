#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<long long> room(n, 0), cnt(n, 0);
    ranges::sort(meetings, {}, [](auto &p) {
        return p[0];
    });

    for (auto &p : meetings) {
        int l = p[0], r = p[1];
        
        long long minn = INT64_MAX, idx = -1, ok = 0;
        for (int i = 0; i < n; i++) {
            if (l >= room[i]) {
                room[i] = r;
                cnt[i]++;
                ok = 1;
                break;
            }

            if (room[i] < minn) {
                minn = room[i];
                idx = i;
            }
        }

        if (!ok) {
            room[idx] += 1LL * (r - l);
            cnt[idx]++;
        }
    }

    int mx = ranges::max(cnt);
    for (int i = 0; i < n; i++) {
        if (cnt[i] == mx) {
            return i;
        }
    }

    return 0;
}

int mostBooked(int n, vector<vector<int>> &meetings)
{
    ranges::sort(meetings, {}, [](auto &p)
                 { return p[0]; });

    priority_queue<int, vector<int>, greater<>> vacant;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        vacant.push(i);
    }

    vector<int> cnt(n);
    for (auto &m : meetings)
    {
        long long start = m[0], end = m[1];

        while (!pq.empty() && pq.top().first <= start)
        {
            vacant.push(pq.top().second);
            pq.pop();
        }

        int idx = -1;
        if (!vacant.empty())
        {
            idx = vacant.top();
            vacant.pop();
        }
        else
        {
            auto [endTime, x] = pq.top();
            pq.pop();

            idx = x;
            end += 1LL * (endTime - start);
        }

        cnt[idx]++;
        pq.emplace(end, idx);
    }

    return ranges::max_element(cnt) - cnt.begin();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 正面难做难想吗? 要不试试反面? 正逆序都试试
5. 此题有单调性吗? 可以二分答案吗?
6. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
7. 贡献法可以做吗?
8. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/