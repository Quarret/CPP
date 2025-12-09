#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxEvents(vector<vector<int>>& events) {
    int mx = 0;
    for (auto &e : events) {
        mx = max(mx, e[1]);
    }

    // 按开始时间分组
    vector<vector<int>> groups(mx + 1);
    for (auto &e : events) {
        groups[e[0]].push_back(e[1]);
    }

    int ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i <= mx; i++) { // 按时间从小到大, 代表会议依次开始
        while (!pq.empty() && i > pq.top()) {
            pq.pop();
        }

        for (int x : groups[i]) {
            pq.push(x);
        }

        // 对于已经开始的会议, 参加结束时间越早的越好
        if (!pq.empty()) {
            ans++;
            pq.pop();
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
