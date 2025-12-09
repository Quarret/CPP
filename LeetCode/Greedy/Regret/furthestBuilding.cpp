#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int> h;
    
    for (int i = 1; i < n; i++) {
        if (heights[i] > heights[i - 1]) {
            int diff = heights[i] - heights[i - 1];

            if (bricks >= diff) {
                bricks -= diff;
                h.push(diff);
            } else if (ladders > 0) {
                // 可能当前最大
                bricks -= diff;
                h.push(diff);

                bricks += h.top();
                h.pop();
                ladders--;
            } else {
                return i;
            }
        }
    }

    return n - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
