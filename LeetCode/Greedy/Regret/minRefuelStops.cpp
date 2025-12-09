#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    stations.push_back({target, 0});
    
    int ans = 0, n = stations.size();
    priority_queue<int> pq;
    for (int i = 1; i < n; i++) {
        int diff = stations[i][0] - (i == 1 ? 0 : stations[i - 1][0]);
        int fuel = stations[i][1];

        while (!pq.empty() && startFuel < diff) {
            ans++;
            startFuel += pq.top();
            pq.pop();
        }

        if (startFuel < diff) {
            return -1;
        } else {
            startFuel -= diff;
            pq.push(fuel);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
