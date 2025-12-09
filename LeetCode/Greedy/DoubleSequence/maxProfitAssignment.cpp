#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = profit.size(), m = worker.size();
    
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](int i) {
        return -profit[i];
    });

    ranges::sort(worker, greater());
    int j = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && worker[i] < difficulty[idxs[j]]) {
            j++;
        }

        if (j != n) {
            ans += profit[idxs[j]];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
