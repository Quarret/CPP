#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxSpending(vector<vector<int>>& values) {
    int m = values.size(), n = values[0].size();
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(values[i][j]);
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < m * n; i++) {
        ans += 1LL * (i + 1) * pq.top();
        pq.pop();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
