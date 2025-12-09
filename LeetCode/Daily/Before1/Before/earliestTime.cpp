#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int earliestTime(vector<vector<int>>& tasks) {
    int ans = 1e9;

    for (auto &task : tasks) {
        ans = min(ans, task[0] + task[1]);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
