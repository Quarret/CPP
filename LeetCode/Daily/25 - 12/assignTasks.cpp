#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
{
    int n = servers.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> vacant;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        vacant.emplace(servers[i], i);
    }

    int m = tasks.size();
    long long t = 0; // 最小空服务器时间
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        while (!pq.empty() && pq.top().first <= i)
        {
            vacant.emplace(servers[pq.top().second], pq.top().second);
            pq.pop();
        }

        if (vacant.empty())
        {
            t = pq.top().first;

            // 当无空闲时, 下线所有相同最小值的服务器
            while (!pq.empty() && pq.top().first == t)
            {
                int id = pq.top().second;
                vacant.emplace(servers[id], id);
                pq.pop();
            }
        }

        t = max(1LL * i, t);
        pq.emplace(t + 1LL * tasks[i], vacant.top().second);
        ans[i] = vacant.top().second;
        vacant.pop();
    }

    return ans;
}
int main()
{
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