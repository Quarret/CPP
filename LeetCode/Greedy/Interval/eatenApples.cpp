#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 吃较早腐烂的苹果
int eatenApples(vector<int>& apples, vector<int>& days) {
    int ans = 0, n = apples.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n || !pq.empty(); i++) {
        while (!pq.empty() && pq.top().first == i) {
            pq.pop();
        }

        if (i < n && apples[i]) {
            pq.emplace(i + days[i], apples[i]);
        }

        if (!pq.empty()) {
            ans++;
            auto[rotten_day, c] = pq.top();
            pq.pop();
            c--;

            if (c) {
                pq.emplace(rotten_day, c);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
